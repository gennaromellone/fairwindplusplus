//
// Created by debian on 11/30/21.
//

#ifndef FAIRWIND_ISETTINGS_H
#define FAIRWIND_ISETTINGS_H

#include <FairWindSdk/IApp.hpp>

namespace fairwind::ui::settings {
    /*
     * ISettings
     * This interface is used by FairWind to implement a set of allowed and curated settings widgets.
     */
    class ISettings{
    public:
        virtual ~ISettings() = default;

        /*
         * setDetails
         * This method sets the state of the widget
         */
        virtual void setDetails(QString settingsID, QJsonObject settings, fairwind::apps::IApp* extension) = 0;

        /*
         * getNewInstance
         * Returns a new instance of ISettings
         */
        virtual ISettings* getNewInstance() = 0;

        /*
         * getClassName
         * Returns the class name of the settings
         */
        virtual QString getClassName() = 0;
    };
}

#endif //FAIRWIND_ISETTINGS_H
