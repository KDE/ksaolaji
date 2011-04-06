#ifndef CLEANER_H
#define CLEANER_H

/** @file cleaner.h is part of KSaoLaJi and defines interface @class Cleaner. */
#include <QString>

/** @namespace KSaoLaJi collects classes related to implementing a cleaner. */
namespace KSaoLaJi {

/**
 * @class Cleaner ksaolaji/cleaner.h
 * @short The base Cleaner class
 * Cleaner defines the common interface for implementing a cleaner in KSaoLaJi.
 * You should subclass @class CleanerPlugin to write a cleaner plugin.
 *
 * @author Ni Hui <shuizhuyuanluo@126.com>
 * @date 2011/4/6
 */
class Cleaner
{
    public:
        /**
         * Constructor
         * The default base class routine does nothing.
         * Cleaner plugin can do initializing in class constructor.
         */
        explicit Cleaner() {}

        /**
         * Destructor
         * The default base class routine does nothing.
         */
        virtual ~Cleaner() {}

        /**
         * @return whether saolaji() function is thread safe or not
         * note: KIO is not thread-safe
         * The default implementation returns false
         */
        virtual bool isThreadSafe() const { return false; }

        /**
         * @return the unique name of this cleaner
         * The unique name is used to work as the identifier of this cleaner.
         * A proper name should be both meaningful and easy to recognize.
         * @b appfoo_recent_files is preferred, while @b appfoo is not.
         * The short form of description is usually fine.
         */
        virtual QString uniqueName() = 0;

        /**
         * @return the description of this cleaner
         * The description string will be displayed in the main list.
         * @code
         * QString CleanerFoo::description()
         * {
         *     return i18n( "AppFoo recent files" );
         * }
         * @endcode
         */
        virtual QString description() = 0;

        /**
         * @return the icon name of this cleaner
         * Return the full path to the icon file if not exists in theme.
         * The icon will be displayed in the cleaner entry.
         */
        virtual QString iconName() = 0;

        /**
         * Perform synchronous checking job.
         * @return @e true if there exists some waste in the system
         * The function name is the abbreviation of the Chinese sentence
         * <em>you mei you la ji ?</em>
         */
        virtual bool youlaji() = 0;

        /**
         * Perform synchronous cleaning job.
         * @return @e true if this cleaner has finished cleaning successfully
         * The function name is the abbreviation of the Chinese phrase
         * <em>sao la ji</em>
         */
        virtual bool saolaji() = 0;
};

}

#endif // CLEANER_H
