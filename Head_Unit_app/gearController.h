#ifndef GEARCONTROLLER_H
#define GEARCONTROLLER_H

#include <QObject>

class GearController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString selectedButton READ selectedButton WRITE setSelectedButton NOTIFY selectedButtonChanged)

public:
    explicit GearController(QObject *parent = nullptr) : QObject(parent), m_selectedButton("P") {}

    QString selectedButton() const { return m_selectedButton; }
    Q_INVOKABLE void setSelectedButton(const QString &button) {
        if (m_selectedButton != button) {
            m_selectedButton = button;
            emit selectedButtonChanged();
        }
    }

signals:
    void selectedButtonChanged();

private:
    QString m_selectedButton;
};

#endif // GEARCONTROLLER_H
