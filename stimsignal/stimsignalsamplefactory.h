#ifndef STIMSIGNALSAMPLEFACTORY_H
#define STIMSIGNALSAMPLEFACTORY_H

#include <QObject>

class StimSignalSampleFactory : public QObject
{
    Q_OBJECT
public:
    explicit StimSignalSampleFactory(QObject *parent = nullptr);

signals:

};

#endif // STIMSIGNALSAMPLEFACTORY_H
