#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    int m_v1=50;
    int m_v2=200;
    int m_v3=350;

private slots:
    void on_actionGuardar_triggered();

    void on_btnpromediar_clicked();

    void on_nota1_valueChanged(int argv);

    void on_nota2_valueChanged(int arg1);

    void on_nota3_valueChanged(int arg1);

private:
    Ui::Principal *ui;
    QPixmap m_lienzo;

    void dibujar(int, int, int);
    void dimension();
};
#endif // PRINCIPAL_H
