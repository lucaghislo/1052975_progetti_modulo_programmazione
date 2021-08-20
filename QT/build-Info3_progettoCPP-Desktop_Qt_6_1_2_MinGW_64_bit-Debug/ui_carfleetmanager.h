/********************************************************************************
** Form generated from reading UI file 'carfleetmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARFLEETMANAGER_H
#define UI_CARFLEETMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarFleetManager
{
public:
    QComboBox *tipoAuto;
    QLineEdit *targa_input;
    QLineEdit *peso_input;
    QLineEdit *potenza_input;
    QLabel *label_capSerbatoio;
    QLineEdit *capSerb_input;
    QLabel *label_consUrbano;
    QLineEdit *consUrbano_input;
    QLineEdit *consCombinato_input;
    QLabel *label_consCombinato;
    QLabel *label_consExtra;
    QLineEdit *consExtra_input;
    QLineEdit *stdCarica3_input;
    QLabel *label_stdCarica3;
    QLabel *label_stdCarica2;
    QLineEdit *stdCarica2_input;
    QLineEdit *stdCarica1_input;
    QLabel *label_stdCarica1;
    QLabel *titolo;
    QPushButton *pulsanteSubmit;
    QLabel *label_tipoAuto;
    QLabel *label_peso;
    QLabel *label_potenza;
    QLabel *label_targa;
    QTextEdit *visualizzatore;

    void setupUi(QWidget *CarFleetManager)
    {
        if (CarFleetManager->objectName().isEmpty())
            CarFleetManager->setObjectName(QString::fromUtf8("CarFleetManager"));
        CarFleetManager->resize(800, 600);
        tipoAuto = new QComboBox(CarFleetManager);
        tipoAuto->addItem(QString());
        tipoAuto->addItem(QString());
        tipoAuto->addItem(QString());
        tipoAuto->setObjectName(QString::fromUtf8("tipoAuto"));
        tipoAuto->setGeometry(QRect(150, 220, 181, 22));
        targa_input = new QLineEdit(CarFleetManager);
        targa_input->setObjectName(QString::fromUtf8("targa_input"));
        targa_input->setGeometry(QRect(150, 130, 181, 21));
        peso_input = new QLineEdit(CarFleetManager);
        peso_input->setObjectName(QString::fromUtf8("peso_input"));
        peso_input->setGeometry(QRect(150, 160, 181, 21));
        potenza_input = new QLineEdit(CarFleetManager);
        potenza_input->setObjectName(QString::fromUtf8("potenza_input"));
        potenza_input->setGeometry(QRect(150, 190, 181, 21));
        label_capSerbatoio = new QLabel(CarFleetManager);
        label_capSerbatoio->setObjectName(QString::fromUtf8("label_capSerbatoio"));
        label_capSerbatoio->setGeometry(QRect(20, 250, 121, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rubik")});
        font.setPointSize(13);
        label_capSerbatoio->setFont(font);
        label_capSerbatoio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        capSerb_input = new QLineEdit(CarFleetManager);
        capSerb_input->setObjectName(QString::fromUtf8("capSerb_input"));
        capSerb_input->setGeometry(QRect(150, 250, 181, 21));
        label_consUrbano = new QLabel(CarFleetManager);
        label_consUrbano->setObjectName(QString::fromUtf8("label_consUrbano"));
        label_consUrbano->setGeometry(QRect(20, 280, 121, 21));
        label_consUrbano->setFont(font);
        label_consUrbano->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        consUrbano_input = new QLineEdit(CarFleetManager);
        consUrbano_input->setObjectName(QString::fromUtf8("consUrbano_input"));
        consUrbano_input->setGeometry(QRect(150, 280, 181, 21));
        consCombinato_input = new QLineEdit(CarFleetManager);
        consCombinato_input->setObjectName(QString::fromUtf8("consCombinato_input"));
        consCombinato_input->setGeometry(QRect(150, 310, 181, 21));
        label_consCombinato = new QLabel(CarFleetManager);
        label_consCombinato->setObjectName(QString::fromUtf8("label_consCombinato"));
        label_consCombinato->setGeometry(QRect(10, 310, 131, 21));
        label_consCombinato->setFont(font);
        label_consCombinato->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_consExtra = new QLabel(CarFleetManager);
        label_consExtra->setObjectName(QString::fromUtf8("label_consExtra"));
        label_consExtra->setGeometry(QRect(20, 340, 121, 21));
        label_consExtra->setFont(font);
        label_consExtra->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        consExtra_input = new QLineEdit(CarFleetManager);
        consExtra_input->setObjectName(QString::fromUtf8("consExtra_input"));
        consExtra_input->setGeometry(QRect(150, 340, 181, 21));
        stdCarica3_input = new QLineEdit(CarFleetManager);
        stdCarica3_input->setObjectName(QString::fromUtf8("stdCarica3_input"));
        stdCarica3_input->setGeometry(QRect(150, 430, 181, 21));
        label_stdCarica3 = new QLabel(CarFleetManager);
        label_stdCarica3->setObjectName(QString::fromUtf8("label_stdCarica3"));
        label_stdCarica3->setGeometry(QRect(20, 430, 121, 21));
        label_stdCarica3->setFont(font);
        label_stdCarica3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_stdCarica2 = new QLabel(CarFleetManager);
        label_stdCarica2->setObjectName(QString::fromUtf8("label_stdCarica2"));
        label_stdCarica2->setGeometry(QRect(10, 400, 131, 21));
        label_stdCarica2->setFont(font);
        label_stdCarica2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stdCarica2_input = new QLineEdit(CarFleetManager);
        stdCarica2_input->setObjectName(QString::fromUtf8("stdCarica2_input"));
        stdCarica2_input->setGeometry(QRect(150, 400, 181, 21));
        stdCarica1_input = new QLineEdit(CarFleetManager);
        stdCarica1_input->setObjectName(QString::fromUtf8("stdCarica1_input"));
        stdCarica1_input->setGeometry(QRect(150, 370, 181, 21));
        label_stdCarica1 = new QLabel(CarFleetManager);
        label_stdCarica1->setObjectName(QString::fromUtf8("label_stdCarica1"));
        label_stdCarica1->setGeometry(QRect(20, 370, 121, 21));
        label_stdCarica1->setFont(font);
        label_stdCarica1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titolo = new QLabel(CarFleetManager);
        titolo->setObjectName(QString::fromUtf8("titolo"));
        titolo->setGeometry(QRect(30, 50, 291, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rubik")});
        font1.setPointSize(18);
        font1.setBold(true);
        titolo->setFont(font1);
        titolo->setAlignment(Qt::AlignCenter);
        pulsanteSubmit = new QPushButton(CarFleetManager);
        pulsanteSubmit->setObjectName(QString::fromUtf8("pulsanteSubmit"));
        pulsanteSubmit->setGeometry(QRect(70, 500, 201, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rubik")});
        font2.setPointSize(14);
        font2.setBold(true);
        pulsanteSubmit->setFont(font2);
        label_tipoAuto = new QLabel(CarFleetManager);
        label_tipoAuto->setObjectName(QString::fromUtf8("label_tipoAuto"));
        label_tipoAuto->setGeometry(QRect(20, 220, 121, 21));
        label_tipoAuto->setFont(font);
        label_tipoAuto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_peso = new QLabel(CarFleetManager);
        label_peso->setObjectName(QString::fromUtf8("label_peso"));
        label_peso->setGeometry(QRect(20, 190, 121, 21));
        label_peso->setFont(font);
        label_peso->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_potenza = new QLabel(CarFleetManager);
        label_potenza->setObjectName(QString::fromUtf8("label_potenza"));
        label_potenza->setGeometry(QRect(20, 160, 121, 21));
        label_potenza->setFont(font);
        label_potenza->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_targa = new QLabel(CarFleetManager);
        label_targa->setObjectName(QString::fromUtf8("label_targa"));
        label_targa->setGeometry(QRect(20, 130, 121, 21));
        label_targa->setFont(font);
        label_targa->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        visualizzatore = new QTextEdit(CarFleetManager);
        visualizzatore->setObjectName(QString::fromUtf8("visualizzatore"));
        visualizzatore->setGeometry(QRect(380, 20, 391, 551));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Courier New")});
        font3.setPointSize(12);
        visualizzatore->setFont(font3);
        visualizzatore->setReadOnly(true);

        retranslateUi(CarFleetManager);

        QMetaObject::connectSlotsByName(CarFleetManager);
    } // setupUi

    void retranslateUi(QWidget *CarFleetManager)
    {
        CarFleetManager->setWindowTitle(QCoreApplication::translate("CarFleetManager", "Car Fleet Manager 1.0", nullptr));
        tipoAuto->setItemText(0, QCoreApplication::translate("CarFleetManager", "Auto Tradizionale", nullptr));
        tipoAuto->setItemText(1, QCoreApplication::translate("CarFleetManager", "Auto Elettrica", nullptr));
        tipoAuto->setItemText(2, QCoreApplication::translate("CarFleetManager", "Auto Ibrida", nullptr));

        label_capSerbatoio->setText(QCoreApplication::translate("CarFleetManager", "Cap. Serbatoio", nullptr));
        label_consUrbano->setText(QCoreApplication::translate("CarFleetManager", "Con. Urbano", nullptr));
        label_consCombinato->setText(QCoreApplication::translate("CarFleetManager", "Con. Combinato", nullptr));
        label_consExtra->setText(QCoreApplication::translate("CarFleetManager", "Con. Extraurb.", nullptr));
        label_stdCarica3->setText(QCoreApplication::translate("CarFleetManager", "Std. ricarica 3", nullptr));
        label_stdCarica2->setText(QCoreApplication::translate("CarFleetManager", "Std. ricarica 2", nullptr));
        label_stdCarica1->setText(QCoreApplication::translate("CarFleetManager", "Std. ricarica 1", nullptr));
        titolo->setText(QCoreApplication::translate("CarFleetManager", "Car Fleet Manager 1.0", nullptr));
        pulsanteSubmit->setText(QCoreApplication::translate("CarFleetManager", "AGGIUNGI AUTO", nullptr));
        label_tipoAuto->setText(QCoreApplication::translate("CarFleetManager", "Alimentazione", nullptr));
        label_peso->setText(QCoreApplication::translate("CarFleetManager", "Peso", nullptr));
        label_potenza->setText(QCoreApplication::translate("CarFleetManager", "Potenza", nullptr));
        label_targa->setText(QCoreApplication::translate("CarFleetManager", "Targa", nullptr));
        visualizzatore->setHtml(QCoreApplication::translate("CarFleetManager", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarFleetManager: public Ui_CarFleetManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARFLEETMANAGER_H
