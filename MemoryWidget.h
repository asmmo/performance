#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include <SysInfoWidget.h>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>


class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    MemoryWidget(QWidget* = nullptr);
    protected slots:
    void updateSeries() override;
private:
    QtCharts::QLineSeries* series;
    qint64 pointPositionX;
};

#endif // MEMORYWIDGET_H
