#ifndef YOUTUBECONTROLLER_H
#define YOUTUBECONTROLLER_H

#include <QObject>

class YoutubeController : public QObject {
    Q_OBJECT
public:
    explicit YoutubeController(QObject *parent = nullptr);

    Q_INVOKABLE QString getYoutubeHtml() const;

private:
    QString apiKey;
};

#endif // YOUTUBECONTROLLER_H
