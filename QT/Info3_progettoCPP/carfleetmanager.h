#ifndef CARFLEETMANAGER_H
#define CARFLEETMANAGER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CarFleetManager; }
QT_END_NAMESPACE

class CarFleetManager : public QWidget
{
    Q_OBJECT

public:
    CarFleetManager(QWidget *parent = nullptr);
    ~CarFleetManager();

private slots:
    void on_pulsanteSubmit_clicked();

    void on_tipoAuto_currentIndexChanged(int index);

private:
    Ui::CarFleetManager *ui;
};
#endif // CARFLEETMANAGER_H
