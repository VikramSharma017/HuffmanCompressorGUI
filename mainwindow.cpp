#include "huffman.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Include your Huffman compress/decompress headers here
#include "huffman.h"
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_browseInput_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select Input File");
    if (!fileName.isEmpty()) {
        ui->inputLineEdit->setText(fileName);
    }
}

void MainWindow::on_browseOutput_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Select Output File");
    if (!fileName.isEmpty()) {
        ui->outputLineEdit->setText(fileName);
    }
}

void MainWindow::compressFile(const QString& inputPath, const QString& outputPath) {
    std::ifstream in(inputPath.toStdString(), std::ios::binary);
    if (!in) {
        QMessageBox::warning(this, "Error", "Cannot open input file");
        return;
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string text = buffer.str();
    in.close();

    ui->progressBar->setValue(10);

    compress(text, outputPath.toStdString());

    ui->progressBar->setValue(80);

    // Calculate compression ratio
    std::ifstream orig(inputPath.toStdString(), std::ios::binary | std::ios::ate);
    std::ifstream comp(outputPath.toStdString(), std::ios::binary | std::ios::ate);
    if (!orig || !comp) {
        QMessageBox::warning(this, "Error", "Cannot open files to calculate compression ratio");
        return;
    }
    auto origSize = orig.tellg();
    auto compSize = comp.tellg();

    double ratio = (origSize > 0) ? (static_cast<double>(compSize) / origSize) * 100.0 : 0;
    ui->progressBar->setValue(100);

    ui->statusLabel->setText(QString("Compression ratio: %1%").arg(ratio, 0, 'f', 2));
}

void MainWindow::decompressFile(const QString& inputPath, const QString& outputPath) {
    decompress(inputPath.toStdString(), outputPath.toStdString());
    ui->progressBar->setValue(100);
    ui->statusLabel->setText("Decompression completed");
}

void MainWindow::on_compressButton_clicked() {
    QString inputPath = ui->inputLineEdit->text();
    QString outputPath = ui->outputLineEdit->text();
    if (inputPath.isEmpty() || outputPath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select input and output files");
        return;
    }
    compressFile(inputPath, outputPath);
}

void MainWindow::on_decompressButton_clicked() {
    QString inputPath = ui->inputLineEdit->text();
    QString outputPath = ui->outputLineEdit->text();
    if (inputPath.isEmpty() || outputPath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select input and output files");
        return;
    }
    decompressFile(inputPath, outputPath);
}
