#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include <QObject>
#include <QString>
#include <QDir>


class MP3Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString coverImagePath READ coverImagePath NOTIFY coverImagePathChanged)

public:
    explicit MP3Player(QObject *parent = nullptr);

    QString coverImagePath() const;
    Q_INVOKABLE void loadMP3File(const QString &filePath);

signals:
    void coverImagePathChanged();

private:
    QString m_coverImagePath;
    void extractCoverArt(const QString &filePath);
};

#endif // MP3PLAYER_H
