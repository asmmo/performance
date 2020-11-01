#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QTimer>
#include <SysInfo.h>



class SysInfoWidget : public QWidget
{
    Q_OBJECT

    QtCharts::QChartView chartView;
    QTimer refreshTimer;
public:
    SysInfoWidget(QWidget *parent = nullptr, int startDelayMs = 500, int updateSeriesDelayMs = 500);
    QtCharts::QChartView& getChartView();

protected slots:
    virtual void updateSeries() = 0;
};

#endif // SYSINFOWIDGET_H
