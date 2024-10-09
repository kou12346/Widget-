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
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *leaderTab = new QWidget;
    QLabel *leaderLabel = new QLabel("組長:郭至峻\n組員1:郭至峻\n組員2:陳彥妤\n組員3:何睿軒");
    leaderLabel->setStyleSheet("color: black;");
    QVBoxLayout *leaderLayout = new QVBoxLayout;
    leaderLayout->addWidget(leaderLabel);
    leaderTab->setLayout(leaderLayout);

    QWidget *member1Tab = new QWidget;
    QLabel *member1Label = new QLabel("Page:組員1");
    QPushButton *colorButton = new QPushButton("color select");
    QVBoxLayout *member1Layout = new QVBoxLayout;
    member1Layout->addWidget(member1Label);
    member1Layout->addWidget(colorButton);
    member1Tab->setLayout(member1Layout);


    QObject::connect(colorButton, &QPushButton::clicked, [=]() {
        QColor color = QColorDialog::getColor(Qt::white, nullptr, "選擇文字顏色");
        if (color.isValid()) {
            QString colorName = color.name();
            leaderLabel->setStyleSheet(QString("color: %1;").arg(colorName));
        }
    });


    QWidget *member2Tab = new QWidget;
    QLabel *member2Label = new QLabel("Page:組員2");
    QPushButton *styleButton = new QPushButton("Front select");
    QVBoxLayout *member2Layout = new QVBoxLayout;
    member2Layout->addWidget(member2Label);
    member2Layout->addWidget(styleButton);
    member2Tab->setLayout(member2Layout);


    QObject::connect(styleButton, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, leaderLabel->font(), nullptr, "選擇字體");
        if (ok) {
            leaderLabel->setFont(font);
        }
    });

    QWidget *member3Tab = new QWidget;
    QLabel *member3Label = new QLabel("Page:組員3");
    QPushButton *fileButton = new QPushButton("File select");
    QVBoxLayout *member3Layout = new QVBoxLayout;
    member3Layout->addWidget(member3Label);
    member3Layout->addWidget(fileButton);
    member3Tab->setLayout(member3Layout);


    QObject::connect(fileButton, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "選擇檔案", "", "所有檔案 (*.*)");
        if (!filePath.isEmpty()) {
            leaderLabel->setText(filePath);
        }
    });


    tabWidget->addTab(leaderTab, "隊長");
    tabWidget->addTab(member1Tab, "組員1");
    tabWidget->addTab(member2Tab, "組員2");
    tabWidget->addTab(member3Tab, "組員3");

    tabWidget->setWindowTitle("example");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
