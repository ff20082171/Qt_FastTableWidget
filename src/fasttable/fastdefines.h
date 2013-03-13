#ifndef FASTDEFINES_H
#define FASTDEFINES_H

#include <QDebug>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asserting
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_ASSERT(condition)  Q_ASSERT(condition)
#else
    #define FASTTABLE_ASSERT(condition)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Debuging
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
    #define FASTTABLE_DEBUG  qDebug()<<"Debug:"<<Q_FUNC_INFO;
#else
    #define FASTTABLE_DEBUG
#endif

#if 0
    #define FASTTABLE_FREQUENT_DEBUG  FASTTABLE_DEBUG
#else
    #define FASTTABLE_FREQUENT_DEBUG
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Log verbose
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_LOG_VERBOSE(text)  qDebug()<<"V:"<<text;
#else
    #define FASTTABLE_LOG_VERBOSE(text)
#endif

#if 1
    #define FASTTABLE_FREQUENT_LOG_VERBOSE(text)  FASTTABLE_LOG_VERBOSE(text)
#else
    #define FASTTABLE_FREQUENT_LOG_VERBOSE(text)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Log debug
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_LOG_DEBUG(text)  qDebug()<<"D:"<<text;
#else
    #define FASTTABLE_LOG_DEBUG(text)
#endif

#if 1
    #define FASTTABLE_FREQUENT_LOG_DEBUG(text)  FASTTABLE_LOG_DEBUG(text)
#else
    #define FASTTABLE_FREQUENT_LOG_DEBUG(text)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Log warning
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_LOG_WARNING(text)  qWarning()<<"W:"<<text;
#else
    #define FASTTABLE_LOG_WARNING(text)
#endif

#if 1
    #define FASTTABLE_FREQUENT_LOG_WARNING(text)  FASTTABLE_LOG_WARNING(text)
#else
    #define FASTTABLE_FREQUENT_LOG_WARNING(text)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Log error
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_LOG_ERROR(text)  qWarning()<<"E:"<<Q_FUNC_INFO;
#else
    #define FASTTABLE_LOG_ERROR(text)
#endif

#if 1
    #define FASTTABLE_FREQUENT_LOG_ERROR(text)  FASTTABLE_LOG_ERROR(text)
#else
    #define FASTTABLE_FREQUENT_LOG_ERROR(text)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Log fatal
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 1
    #define FASTTABLE_LOG_FATAL(text)  qFatal()<<"F:"<<Q_FUNC_INFO;
#else
    #define FASTTABLE_LOG_FATAL(text)
#endif

#if 1
    #define FASTTABLE_FREQUENT_LOG_FATAL(text)  FASTTABLE_LOG_FATAL(text)
#else
    #define FASTTABLE_FREQUENT_LOG_FATAL(text)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Profiling
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
    #define FASTTABLE_START_PROFILE  qint64 profileStart=QDateTime::currentMSecsSinceEpoch();
    #define FASTTABLE_END_PROFILE    qDebug()<<Q_FUNC_INFO<<":"<<QDateTime::currentMSecsSinceEpoch()-profileStart<<"ms";
#else
    #define FASTTABLE_START_PROFILE
    #define FASTTABLE_END_PROFILE
#endif

#if 0
    #define FASTTABLE_FREQUENT_START_PROFILE  FASTTABLE_START_PROFILE
    #define FASTTABLE_FREQUENT_END_PROFILE    FASTTABLE_END_PROFILE
#else
    #define FASTTABLE_FREQUENT_START_PROFILE
    #define FASTTABLE_FREQUENT_END_PROFILE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FASTTABLE_DEFAULT_TEXT_FLAG        Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap
#define FASTTABLE_HEADER_DEFAULT_TEXT_FLAG Qt::AlignCenter | Qt::TextWordWrap

#define FASTTABLE_TEXT_MARGIN 4

#define FASTTABLE_MOUSE_HOLD_SCROLL_SPEED 15

#define FASTTABLE_MOUSE_RESIZE_THRESHOLD 3
#define FASTTABLE_MOUSE_RESIZE_MINIMUM_WIDTH 20
#define FASTTABLE_MOUSE_RESIZE_MINIMUM_HEIGHT 8

#endif // FASTDEFINES_H
