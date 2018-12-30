#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <QObject>

class Levenshtein : public QObject
{
    Q_OBJECT
public:
    explicit Levenshtein(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LEVENSHTEIN_H