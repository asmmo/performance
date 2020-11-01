#include "CpuWidget.h"

CpuWidget::CpuWidget(QWidget* parent): SysInfoWidget(parent), series{new QtCharts::QPieSeries{this}}
{
    //The series was initialized on constructing, then It's being configured below
    series -> setHoleSize(0.35);
    series -> append("CPU Load", 30.0);
    series -> append("CPU Free", 70.0);

    //transfering the ownership of series to the chart
    getChartView().chart() -> addSeries(series);
    getChartView().chart() -> setTitle("CPU average load");

}


void CpuWidget::updateSeries()
{
    double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();
    series->clear();
    series->append("Load", cpuLoadAverage);
    series->append("Free", 100.0 - cpuLoadAverage);
}
