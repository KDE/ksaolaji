#ifndef CLEANER_H
#define CLEANER_H

#include <QObject>
#include <QString>

class Cleaner : public QObject
{
    Q_OBJECT
    public:
        explicit Cleaner( QObject* parent = 0 );
        virtual ~Cleaner();
        virtual QString description() = 0;
        virtual QString iconName() = 0;

        /** you mei you la ji ? */
        virtual bool youlaji() = 0;
        /** sao la ji */
        virtual bool saolaji() = 0;
};

#endif // CLEANER_H
