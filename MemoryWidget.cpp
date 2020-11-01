#include "MemoryWidget.h"
const int CHART_X_RANGE_COUNT = 50;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;
MemoryWidget::MemoryWidget(QWidget* parent): SysInfoWidget{parent},
    series{new QtCharts::QLineSeries{this}}
    , pointPositionX{}
{
    QtCharts::QAreaSeries* areaSeries = new QtCharts::QAreaSeries(series);
    QtCharts::QChart* chart = getChartView().chart();
    chart->addSeries(areaSeries);
    chart->setTitle("Memory used");
    chart->createDefaultAxes();
    chart->axisX()->setVisible(false);
    chart->axisX()->setRange(0, CHART_X_RANGE_MAX);
    chart->axisY()->setRange(0, 100);

    //    chart->addAxis(pointPositionX, Qt::AlignBottom)->setVisible(false);

}


void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
    series->append(pointPositionX++, memoryUsed);
    if (series->count() > CHART_X_RANGE_COUNT) {

        getChartView().chart() -> scroll( getChartView().chart() -> plotArea().width() / CHART_X_RANGE_MAX, 0);
        series->remove(0);
    }
}
