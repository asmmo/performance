#include "SysInfoWidget.h"
#include <QVBoxLayout>

SysInfoWidget::SysInfoWidget(QWidget *parent, int startDelayMs, int updateSeriesDelayMs) :
QWidget(parent), chartView(this)
{
    refreshTimer.setInterval(updateSeriesDelayMs);
    connect(&refreshTimer, &QTimer::timeout, this, &SysInfoWidget::updateSeries);
    refreshTimer.start(startDelayMs);
    chartView.setRenderHint(QPainter::Antialiasing);
    chartView.chart()->legend()->setVisible(true);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&chartView);
    setLayout(layout);
}
QtCharts::QChartView& SysInfoWidget::getChartView()
{
    return chartView;
}


