#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTabWidget *TabWidget = new QTabWidget;
    QWidget *LeaderTab = new QWidget;
    QLabel *LeaderLabel = new QLabel("隊長:郭至峻\n組員1:郭至峻\n組員2:\n組員3");
    LeaderLabel->setStyleSheet("color: blue;");
    QVBoxLayout *LeaderLayout = new QVBoxLayout;
    LeaderLayout->addWidget(LeaderLabel);
    LeaderTab->setLayout(LeaderLayout);

    QWidget *member1Tab = new QWidget;
    QLabel *member1Label = new QLabel("這是組員1頁面");
    QPushButton *colorButton = new QPushButton("color select");
    QVBoxLayout *member1Layout = new QVBoxLayout;
    member1Layout->addWidget(member1Label);
    member1Layout->addWidget(colorButton);
    member1Tab->setLayout(member1Layout);


    QObject::connect(colorButton, &QPushButton::clicked, [=]() {
        QColor color = QColorDialog::getColor(Qt::white, nullptr, "選擇文字顏色");
        if (color.isValid()) {
            QString colorName = color.name();
            LeaderLabel->setStyleSheet(QString("color: %1;").arg(colorName));
        }
    });
    TabWidget->addTab(LeaderTab, "隊長");
    TabWidget->addTab(member1Tab, "組員1");


    TabWidget->setWindowTitle("example");
    TabWidget->resize(400, 300);
    TabWidget->show();
    return app.exec();
}
