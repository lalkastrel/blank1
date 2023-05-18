#pragma once

#include <QtWidgets/QWidget>
#include <qvector.h>
#include "qlayout.h"
#include "qlabel.h"
#include "qscrollarea.h"
#include "qlineedit.h"
#include "qdatetimeedit.h"
#include "qcombobox.h"
#include "qcheckbox.h"
#include "qtextedit.h"
#include "qpushbutton.h"
#include "qfile.h"
#include "qdebug.h"
#include <fstream>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
   
private:
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QVector<QHBoxLayout*> layouts;
    QVector<QLabel*> labels;
    QScrollArea* scrollArea = new QScrollArea;

    QLineEdit* que1 = new QLineEdit;
    QLineEdit* que2 = new QLineEdit;
    QLineEdit* que3 = new QLineEdit;
    QDateEdit* que4 = new QDateEdit;
    QTimeEdit* que5 = new QTimeEdit;
    QComboBox* que6 = new QComboBox;
    QComboBox* que7 = new QComboBox;
    QCheckBox* que8 = new QCheckBox;
    QComboBox* que9 = new QComboBox;
    QLineEdit* que10 = new QLineEdit;
    QTextEdit* que11 = new QTextEdit;
    QLineEdit* que12 = new QLineEdit;
    QLineEdit* que13 = new QLineEdit;
    QComboBox* que14 = new QComboBox;
    QLineEdit* que15 = new QLineEdit;
    QLineEdit* que16 = new QLineEdit;
    QLineEdit* que17 = new QLineEdit;
    QComboBox* que18 = new QComboBox;
    QTextEdit* que19 = new QTextEdit;
    QPushButton* que20_1 = new QPushButton;
    QPushButton* que20_2 = new QPushButton;
    QString data;
    QFile* output = new QFile("textForOutput.txt");
    void writeToQString(QChar delimiter);
public slots:
    void writeToFile();
};
