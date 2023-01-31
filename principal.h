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

private slots:
    void on_actionGuardar_triggered();

    void on_nota1_valueChanged(int argv);

    void on_nota2_valueChanged(int argv);

    void on_nota3_valueChanged(int argv);

private:
    Ui::Principal *ui;
    QPixmap m_lienzo;
    int m_v1;
    int m_v2;
    int m_v3;

    void dibujar();
};
#endif // PRINCIPAL_H
