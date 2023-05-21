#include "stimsignalsample.h"
#include <QtMath>

StimSignalSample::StimSignalSample(qlonglong wholeTimestamp, qreal fractionalTimestamp, QObject *parent)
    :
      QObject(parent),
      wholeTimestamp(wholeTimestamp),
      fractionalTimestamp(fractionalTimestamp),
      primaryAmplitude(1),
      secondaryAmplitude(1),
      primaryPhase(0),
      secondaryPhase(0)
{

}

qreal StimSignalSample::getPrimaryPhase() const
{
    return primaryPhase;
}

void StimSignalSample::setPrimaryPhase(const qreal &value)
{
    primaryPhase = value;
    primaryPhase -= (int) primaryPhase;
}

qreal StimSignalSample::getSecondaryPhase() const
{
    return secondaryPhase;
}

void StimSignalSample::setSecondaryPhase(const qreal &value)
{
    secondaryPhase = value;
    secondaryPhase -= (int) secondaryPhase;
}

qreal StimSignalSample::primaryValue()
{
    return primaryAmplitude * qSin(2 * M_PI * primaryPhase);
}

qreal StimSignalSample::secondaryValue()
{
    return secondaryAmplitude * qSin(2 * M_PI * secondaryPhase);
}

qint16 StimSignalSample::primaryPcm()
{
    return realToPcm(primaryValue());
}

qint16 StimSignalSample::secondaryPcm()
{
    return realToPcm(secondaryValue());
}

//!
//! \brief StimSignalSample::distanceToTimestamp
//! \param timestamp the timestamp (in ms) we're working the distance to
//! \return the number of milliseconds to the given timestamp. Positive if it's in the future. Negative if the given timestamp is before this one.
//!
qreal StimSignalSample::distanceToTimestamp(qlonglong timestamp)
{
    qlonglong wholeDistance = timestamp - wholeTimestamp;
    return wholeDistance - fractionalTimestamp;
}

const qint16  PCMS16MaxValue     =  32767;
//const quint16 PCMS16MaxAmplitude =  32768; // because minimum is -32768

qint16 StimSignalSample::realToPcm(qreal real)
{
    return real * PCMS16MaxValue;
}
