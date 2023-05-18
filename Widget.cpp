#include "Widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
{

	for (size_t i = 0; i < 21; i++)
	{
		layouts.push_back(new QHBoxLayout);
		mainLayout->addLayout(layouts[i]);
		labels.push_back(new QLabel);
		layouts[i]->addWidget(labels[i]);
	}
	//labels.push_back(new QLabel);

	this->setLayout(mainLayout);
	labels[0]->setText("1. Your first name");
	labels[1]->setText("2. Your surname");
	labels[2]->setText("3. Your patronomic");
	labels[3]->setText("4. Your birthday");
	labels[4]->setText("5. The time when university starts");
	labels[5]->setText("6. What region are you from"); // box
	labels[6]->setText("7. What you like more"); // coffe, tea , water
	labels[7]->setText("8. Do you like to study"); // yes or no
	labels[8]->setText("9. What subject do you like more");
	labels[9]->setText("10. Name of your pet");
	labels[10]->setText("11. Why did you choose bsu");
	labels[11]->setText("12. What are you doing in free time");
	labels[12]->setText("13. What is your hobby");
	labels[13]->setText("14. Your favourite time of the year");
	labels[14]->setText("15. Your favourite sport");
	labels[15]->setText("16. Your favourite food");
	labels[16]->setText("17. What do you want");
	labels[17]->setText("18. Your favorite colour");
	labels[18]->setText("19. Write about yourself");
	labels[20]->setText("20. ");

	layouts[0]->addWidget(que1);
	layouts[1]->addWidget(que2);
	layouts[2]->addWidget(que3);
	layouts[3]->addWidget(que4);
	layouts[4]->addWidget(que5);
	layouts[5]->addWidget(que6);
	que6->addItem("Minsk");
	que6->addItem("Brest");
	que6->addItem("Vitebsk");
	que6->addItem("Gomel");
	que6->addItem("Grodno");
	que6->addItem("Mogilev");
	layouts[6]->addWidget(que7);
	que7->addItem("Coffee");
	que7->addItem("Tea");
	que7->addItem("Water");
	layouts[7]->addWidget(que8);
	layouts[8]->addWidget(que9);
	que9->addItem("Biology");
	que9->addItem("Chemistry");
	que9->addItem("English");
	que9->addItem("Math");
	que9->addItem("History");
	que9->addItem("Geography");
	que9->addItem("Another");
	layouts[9]->addWidget(que10);
	layouts[10]->addWidget(que11);
	que11->setMaximumHeight(22);
	layouts[11]->addWidget(que12);
	layouts[12]->addWidget(que13);
	layouts[13]->addWidget(que14);
	que14->addItem("Winter");
	que14->addItem("Spring");
	que14->addItem("Summer");
	que14->addItem("Autumn");
	layouts[14]->addWidget(que15);
	layouts[15]->addWidget(que16);
	layouts[16]->addWidget(que17);
	layouts[17]->addWidget(que18);
	que18->addItem("White");
	que18->addItem("Black");
	que18->addItem("Red");
	que18->addItem("Green");
	que18->addItem("Blue");
	que18->addItem("Scarlet");
	que18->addItem("Yellow");
	que18->addItem("Magenta");
	que18->addItem("Cyan");
	que18->addItem("Violet");
	que18->addItem("Purple");
	que18->addItem("Burgundy");
	que18->addItem("Carmine");
	que18->addItem("Other");
	layouts[19]->addWidget(que19);
	layouts[20]->addWidget(que20_1);
	layouts[20]->addWidget(que20_2);
	que20_1->setText("Cancel");
	que20_2->setText("Save");

	QObject::connect(que20_1, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(que20_2, SIGNAL(clicked()), this, SLOT(writeToFile()));
}

Widget::~Widget()
{}

void Widget::writeToQString(QChar delimiter) {
	data += que1->text();
	data += delimiter;
	data += que2->text();
	data += delimiter;
	data += que3->text();
	data += delimiter;
	data += que4->date().toString("dd.MM.yyyy");
	data += delimiter;
	data += que5->time().toString("hh:mm");
	data += delimiter;
	data += que6->currentText();
	data += delimiter;
	data += que7->currentText();
	data += delimiter;
	if (que8->isChecked()) {
		data += "true";
	}
	else {
		data += "false";
	}
	data += delimiter;
	data += que9->currentText();
	data += delimiter;
	data += que10->text();
	data += delimiter;
	data += que11->toPlainText();
	data += delimiter;
	data += que12->text();
	data += delimiter;
	data += que13->text();
	data += delimiter;
	data += que14->currentText();
	data += delimiter;
	data += que15->text();
	data += delimiter;
	data += que16->text();
	data += delimiter;
	data += que17->text();
	data += delimiter;
	data += que18->currentText();
	data += delimiter;
	data += que19->toPlainText();
	data += delimiter;
}

void Widget::writeToFile() {
	writeToQString(';');
	if (output->open(QIODevice::WriteOnly | QIODevice::Text)) {
		output->write(data.toUtf8());
		output->close();
	}
	else {
		qDebug() << "file is not open";
	}

}