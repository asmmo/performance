#ifndef CPUWIDGET_H
#define CPUWIDGET_H
#include <SysInfoWidget.h>
#include <QtCharts/QPieSeries>
#include <SysInfo.h>
class CpuWidget : public SysInfoWidget
{
    Q_OBJECT
    QtCharts::QPieSeries* series;
public:
    CpuWidget(QWidget* = nullptr);

    private slots :
    void updateSeries()override;

};

#endif // CPUWIDGET_H
