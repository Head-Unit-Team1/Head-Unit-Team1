#ifndef GEARCONTROLLER_H
#define GEARCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/ICProxy.hpp>
using namespace v0::commonapi;

class GearController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString selectedButton READ selectedButton WRITE setSelectedButton NOTIFY selectedButtonChanged)

public:
    explicit GearController(QObject *parent = nullptr) : QObject(parent), m_selectedButton("P"), gear_string("P") {
//        QTimer* timer = new QTimer(this);
//        connect(timer, &QTimer::timeout, this, &GearController::logSelectedButton);
//        timer->start(1000);
        runtime = CommonAPI::Runtime::get();
        myProxy = runtime->buildProxy<ICProxy>("local","commonapi.IC_service");
        myProxy->getGearStatusChangedEvent().subscribe([this](const std::string& gearValue){
            m_selectedButton = QString::fromStdString(gearValue);
            emit selectedButtonChanged();
        });
    }

    QString selectedButton() const { return m_selectedButton; }
    std::string gearValue() const { return gear_string; }
    Q_INVOKABLE void setSelectedButton(const QString &button) {
        if (m_selectedButton != button) {
            m_selectedButton = button;
            emit selectedButtonChanged();
        }
        CommonAPI::CallStatus callstatus;
        int32_t result = 1;
        std::string stringGear = m_selectedButton.QString::toStdString();
        myProxy->setGear(stringGear, callstatus, result);
    }
    std::shared_ptr <CommonAPI::Runtime> runtime;
    std::shared_ptr<ICProxy<>> myProxy;

signals:
    void selectedButtonChanged();

private slots:
    void logSelectedButton() {
        qDebug() << "Current selected button: " << m_selectedButton;
    }


private:
    QString m_selectedButton;
    std::string gear_string;
};

#endif // GEARCONTROLLER_H
