#include "chart.h"

void setChartView_Dep(QFrame *frame)
{
    QPieSeries *series = new QPieSeries();
    QSqlQuery query;
    query.prepare("SELECT DEPARTEMENT from EMPLOYEE");
    query.exec();

    int rh = 0;
    int finance = 0;
    int recyclage = 0;
    int autre = 0;

    while (query.next()) {
        if (query.value(0) == "rh") {
            rh++;
        }
        else if (query.value(0) == "finance"){
            finance++;
        }
        else if (query.value(0) == "recyclage") {
            recyclage++;
        }
        else {
            autre++;
        }
    }

    //series->setLabelsVisible();
    series->append("ressources humaines", rh);
    series->append("finance", finance);
    series->append("recyclage", recyclage);
    series->append("autre", autre);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques sur les départements des employés");

    QChartView *view = new QChartView(chart);
    view->setParent(frame);
}

void setChartView_Poste(QFrame *frame)
{
    QPieSeries *series = new QPieSeries();
    QSqlQuery query;
    query.prepare("SELECT POSTE from EMPLOYEE");
    query.exec();

    int chef_dep = 0;
    int secretaire = 0;
    int developpeur = 0;
    int autre = 0;

    while (query.next()) {
        if (query.value(0) == "chef departement") {
            chef_dep++;
        }
        else if (query.value(0) == "secretaire"){
            secretaire++;
        }
        else if (query.value(0) == "developpeur") {
            developpeur++;
        }
        else {
            autre++;
        }
    }

    series->append("chef departement", chef_dep);
    series->append("secrétaire", secretaire);
    series->append("développeur", developpeur);
    series->append("autre", autre);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques sur les postes des employés");

    QChartView *view = new QChartView(chart);
    view->setParent(frame);
}
