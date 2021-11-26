//
// Created by __author__ on 18/07/2021.
//

#include <FairWindSdk/FairWind.hpp>
#include "UAV.hpp"

/*
 * Returns the application icon
 */
QImage fairwind::apps::uav::UAV::getIcon() const {
    return QImage(":/resources/images/icons/uav_icon.png");
}

/*
 * Called by the FairWind framework when the app is invoked for the first time
 */
QWidget *fairwind::apps::uav::UAV::onGui(QMainWindow *mainWindow, QMap<QString, QVariant> args) {

    m_widget=new QWidget();
    ui=new Ui::UAV();
    ui->setupUi(m_widget);

    auto fairwind=::fairwind::FairWind::getInstance();
    auto config = getConfig();

    return m_widget;
}



QString fairwind::apps::uav::UAV::getId() const {
    return AppBase::getId();
}

QString fairwind::apps::uav::UAV::getName() const {
    return AppBase::getName();
}

QString fairwind::apps::uav::UAV::getDesc() const {
    return AppBase::getDesc();
}

QString fairwind::apps::uav::UAV::getVersion() const {
    return fairwind::AppBase::getVersion();
}

QString fairwind::apps::uav::UAV::getVendor() const {
    return fairwind::AppBase::getVendor();
}

QString fairwind::apps::uav::UAV::getCopyright() const {
    return fairwind::AppBase::getCopyright();
}

QString fairwind::apps::uav::UAV::getLicense() const {
    return fairwind::AppBase::getLicense();
}

void fairwind::apps::uav::UAV::onInit(QJsonObject *metaData) {
    AppBase::onInit(metaData);
}

QWidget *fairwind::apps::uav::UAV::onSettings(QTabWidget *tabWidget) {
    return nullptr;
}

QJsonObject fairwind::apps::uav::UAV::getConfig() {
    return AppBase::getConfig();
}

QJsonObject fairwind::apps::uav::UAV::getMetaData() {
    return AppBase::getMetaData();
}

void fairwind::apps::uav::UAV::updateSettings(QString settingsID, QString newValue) {
    QDir appDataPath = QDir(getMetaData()["dataRoot"].toString() + QDir::separator() + getId());

    // Create the path if needed
    appDataPath.mkpath(appDataPath.absolutePath());

    // Set the config.json file
    QFile configsFile(appDataPath.absolutePath() + QDir::separator() + "config.json");
    configsFile.open(QFile::ReadWrite);

    QJsonDocument configsDocument = QJsonDocument().fromJson(configsFile.readAll());

    QJsonObject configs = configsDocument.object();

    QJsonValueRef ref = configs.find("Values").value();
    QJsonObject values = ref.toObject();

    values.insert(settingsID, newValue);

    ref = values;

    configsDocument.setObject(configs);

    if (configsFile.resize(0))
        configsFile.write(configsDocument.toJson());

    configsFile.close();
    setConfig(configs);
}

void fairwind::apps::uav::UAV::setConfig(QJsonObject config) {
    AppBase::setConfig(config);
}