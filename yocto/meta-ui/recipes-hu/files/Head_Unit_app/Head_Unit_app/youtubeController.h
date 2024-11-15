#ifndef YOUTUBECONTROLLER_H
#define YOUTUBECONTROLLER_H

#include <QObject>

class YoutubeController : public QObject {
    Q_OBJECT
public:
    explicit YoutubeController(QObject *parent = nullptr);

    Q_INVOKABLE QString getYoutubeHtml() const;
    Q_INVOKABLE QString getYoutubeHtmlForRank(int rank) const;

private:
    QString apiKey;
};

#endif // YOUTUBECONTROLLER_H
