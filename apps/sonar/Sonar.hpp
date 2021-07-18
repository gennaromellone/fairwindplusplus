//
// Created by Raffaele Montella on 15/07/21.
//

#ifndef SONAR_HPP
#define SONAR_HPP

#include <QObject>
#include <QtPlugin>
#include <FairWindSdk/AppBase.hpp>
#include <FairWindSdk/IApp.hpp>
#include "ui_Sonar.h"
#include "ui_Sonar_Settings.h"

namespace fairwind::apps::sonar {
    class Sonar : public QObject, ::fairwind::AppBase, ::fairwind::apps::IApp {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID IID_FAIRWIND_APPS FILE "manifest.json")
        Q_INTERFACES(fairwind::apps::IApp)

    public:
        ~Sonar() = default;

        void onInit(QJsonObject *metaData) override;

        QString getId() const override;
        QString getName() const override;
        QString getDesc() const override;
        QString getVersion() const override;
        QString getVendor() const override;
        QString getCopyright() const override;
        QString getLicense() const override;

        QImage getIcon() const override;
        QWidget *onGui(QMainWindow *mainWindow, QMap<QString, QVariant> args) override;
        QWidget *onSettings(QTabWidget *tabWidgets) override;

        QJsonObject getConfig() override;
        QJsonObject getMetaData() override;

    private:
        Ui::Sonar *ui;
        Ui::sonar_Settings *uiSettings;
        QWidget *m_widget= nullptr;
    };
}

#endif //SONAR_HPP
