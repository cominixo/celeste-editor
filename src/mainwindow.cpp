#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), celesteCart()
{
    ui->setupUi(this);
    //connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveCart()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadCart()));
}

void MainWindow::saveCart() {
     // make this later
}

void MainWindow::loadCart() {

    QFileDialog fileDialog(this, (""),
                           QDir::homePath(),
                           ("Pico-8 Cart (*.p8)"));

    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);

    if (fileDialog.exec()) {

        QString fileName = fileDialog.selectedFiles().at(0);

        celesteCart.loadFile(fileName);
        std::vector<QImage> sprites = celesteCart.spritesImage;

        QImage map = celesteCart.getMapImage();

        // testing map image
        QPixmap pixmap = QPixmap();
        pixmap.convertFromImage(map);
        ui->label->setPixmap(pixmap);

    }
}

MainWindow::~MainWindow() {
    delete ui;
}
