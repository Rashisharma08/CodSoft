#include <QtWidgets>
#include <opencv2/opencv.hpp>

class ImageProcessingTool : public QMainWindow {
    Q_OBJECT

public:
    ImageProcessingTool(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUi();
        connectSignals();
    }

private slots:
    void loadImage();
    void applyGrayscale();
    // Other image processing slots...

private:
    void setupUi();
    void connectSignals();

    QLabel *imageLabel;
    QImage qImage;
    cv::Mat cvImage;
};

void ImageProcessingTool::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    imageLabel = new QLabel;
    layout->addWidget(imageLabel);

    QPushButton *loadButton = new QPushButton("Load Image");
    layout->addWidget(loadButton);

    // Other UI elements for image processing operations...

    resize(800, 600);
}

void ImageProcessingTool::connectSignals() {
    connect(loadButton, &QPushButton::clicked, this, &ImageProcessingTool::loadImage);
    connect(grayscaleButton, &QPushButton::clicked, this, &ImageProcessingTool::applyGrayscale);
    // Connect other signals to slots...
}

void ImageProcessingTool::loadImage() {
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!imagePath.isEmpty()) {
        cvImage = cv::imread(imagePath.toStdString());
        if (!cvImage.empty()) {
            cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB); // Convert BGR to RGB
            qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
            imageLabel->setPixmap(QPixmap::fromImage(qImage));
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to load image."));
        }
    }
}

void ImageProcessingTool::applyGrayscale() {
    if (!cvImage.empty()) {
        cv::Mat grayscaleImage;
        cv::cvtColor(cvImage, grayscaleImage, cv::COLOR_RGB2GRAY);
        cv::cvtColor(grayscaleImage, cvImage, cv::COLOR_GRAY2RGB);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageLabel->setPixmap(QPixmap::fromImage(qImage));
    }
}

// Implement other image processing slots...

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageProcessingTool tool;
    tool.show();
    return app.exec();
}

#include "main.moc"
