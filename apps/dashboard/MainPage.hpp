//
// Created by Raffaele Montella on 11/01/22.
//

#ifndef FAIRWIND_MAINPAGE_HPP
#define FAIRWIND_MAINPAGE_HPP

#include <QWidget>
#include <FairWindSdk/IFairWindApp.hpp>
#include <FairWindSdk/PageBase.hpp>

namespace fairwind::apps::dashboard {
    QT_BEGIN_NAMESPACE
    namespace Ui { class MainPage; }
    QT_END_NAMESPACE

    class MainPage : public PageBase {
    Q_OBJECT

    public:
        explicit MainPage(QWidget *parent, FairWindApp *fairWindApp);

        ~MainPage() ;

    private:
        Ui::MainPage *ui;

    };
} // fairwind::apps::Dashboard

#endif //FAIRWIND_MAINPAGE_HPP
