#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <QObject>
#include <QString>
#include <QVector>

class Levenshtein : public QObject
{
    Q_OBJECT
    int edit_dist(QString s1, int a, QString s2, int b);
public:
    explicit Levenshtein(QVector <QString> inputs, QObject *parent = nullptr);
    QString matrix, distance;
signals:

public slots:
};

#endif // LEVENSHTEIN_H
