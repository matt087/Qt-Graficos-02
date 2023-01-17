#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_lienzo = QPixmap(500,500);
    this->dibujar(m_v1,m_v2,m_v3);

    ui->outCuadro->setPixmap(m_lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar(int m_v1, int m_v2, int m_v3)
{
    m_lienzo.fill(Qt::white);

    QPainter painter(&m_lienzo);

    int x = 30;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Dibujar primera barra
    painter.drawRect(x+50, y+m_v1,100,400);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Dibujar segunda barra
    painter.drawRect(x+170, y+m_v2, 100, 250+m_v2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,y+m_v3,100,100);
}

void Principal::dimension()
{
    int v1 = ui->nota1->text().toInt();
    m_v1=(400*v1)/100;
    int v2 = ui->nota2->text().toInt();
    m_v2=(400*v2)/100;
    int v3 = ui->nota3->text().toInt();
    m_v3=(400*v3)/100;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (m_lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_btnpromediar_clicked()
{

}




void Principal::on_nota1_valueChanged(int argv)
{
    dimension();
    this->dibujar(m_v1,m_v2,m_v3);
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_nota2_valueChanged(int arg1)
{
    dimension();
    this->dibujar(m_v1,m_v2,m_v3);
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_nota3_valueChanged(int arg1)
{
    dimension();
    this->dibujar(m_v1,m_v2,m_v3);
    ui->outCuadro->setPixmap(m_lienzo);
}

