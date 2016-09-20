#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QtAdMob/QtAdMobBanner.h"
#include "QtAdMob/QtAdMobInterstitial.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_Switch(false)
{
    ui->setupUi(this);

    m_Banner = CreateQtAdMobBanner();
    m_Banner->setUnitId("ca-app-pub-7485900711629006/8288667458");
    m_Banner->setSize(IQtAdMobBanner::Banner);
    m_Banner->addTestDevice("514ED2E95AD8EECE454CC5565326160A");

    m_Interstitial = CreateQtAdMobInterstitial();
    m_Interstitial->addTestDevice("514ED2E95AD8EECE454CC5565326160A");

    connect(m_Banner, SIGNAL(loaded()), this, SLOT(OnBannerLoaded()));
    connect(m_Banner, SIGNAL(loading()), this, SLOT(OnBannerLoading()));
    connect(m_Interstitial, SIGNAL(loaded()), this, SLOT(OnInterstitialLoaded()));
    connect(m_Interstitial, SIGNAL(loading()), this, SLOT(OnInterstitialLoading()));
    connect(m_Interstitial, SIGNAL(closed()), this, SLOT(OnInterstitialClosed()));

    m_Banner->setVisible(true);
    m_Interstitial->setUnitId("ca-app-pub-7485900711629006/9462519453");

    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(OnButtonOkClicked()));
    connect(ui->interstitialButton, SIGNAL(clicked()), this, SLOT(OnButtonInterstitialClicked()));
}

MainWindow::~MainWindow()
{
    delete m_Banner;
    delete m_Interstitial;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    QPoint position((width() - m_Banner->sizeInPixels().width()) * 0.5f, 0.0f);
    m_Banner->setPosition(position);
}

void MainWindow::OnButtonOkClicked()
{
    bool isShowed = m_Banner->visible();
    if (!isShowed)
    {
        m_Banner->setVisible(true);
        ui->okButton->setText("Hide Banner");
    }
    else
    {
        m_Banner->setVisible(false);
        ui->okButton->setText("Show Banner");
    }
}

void MainWindow::OnBannerLoaded()
{
    bool isShowed = m_Banner->visible();
    if (isShowed)
    {
        ui->okButton->setText("Hide Banner");
    }
    else
    {
        ui->okButton->setText("Show Banner");
    }
    ui->okButton->setEnabled(true);

    QPoint position((width() - m_Banner->sizeInPixels().width()) * 0.5f, 0.0f);
    m_Banner->setPosition(position);
}

void MainWindow::OnBannerLoading()
{
    ui->okButton->setText("Loading..");
    ui->okButton->setEnabled(false);
}

void MainWindow::OnButtonInterstitialClicked()
{
    if (m_Interstitial->isLoaded())
    {
        m_Interstitial->setVisible(true);
    }
}

void MainWindow::OnInterstitialLoaded()
{
    ui->interstitialButton->setText("Show Interstitial");
    ui->interstitialButton->setEnabled(true);
}

void MainWindow::OnInterstitialLoading()
{
    ui->interstitialButton->setText("Loading..");
    ui->interstitialButton->setEnabled(false);
}

void MainWindow::OnInterstitialClosed()
{
    m_Interstitial->setUnitId("ca-app-pub-7485900711629006/9462519453");
}
