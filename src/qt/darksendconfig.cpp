#include "darksendconfig.h"
#include "ui_darksendconfig.h"

#include "guiconstants.h"
#include "walletmodel.h"
#include "init.h"

#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>
#include <QSettings>

DarksendConfig::DarksendConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DarksendConfig),
    model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

DarksendConfig::~DarksendConfig()
{
    delete ui;
}

void DarksendConfig::setModel(WalletModel *model)
{
    this->model = model;
}

void DarksendConfig::clickBasic()
{
    configure(true, 1000, 2);

    QMessageBox::information(this, tr("Darksend Configuration"),
                         tr("Darksend was successfully set to basic (1000 CRU and 2 rounds). You can change this at any time by opening Curium's configuration screen."));

    close();
}

void DarksendConfig::clickHigh()
{
    configure(true, 1000, 4);

    QMessageBox::information(this, tr("Darksend Configuration"),
                         tr("Darksend was successfully set to high (1000 CRU and 4 rounds). You can change this at any time by opening Curium's configuration screen."));

    close();
}

void DarksendConfig::clickMax()
{
    configure(true, 1000, 8);

    QMessageBox::information(this, tr("Darksend Configuration"),
                         tr("Darksend was successfully set to maximum (1000 CRU and 8 rounds). You can change this at any time by opening Curium's configuration screen."));

    close();
}

void DarksendConfig::configure(bool enabled, int coins, int rounds) {

    QSettings settings;

    settings.setValue("nDarksendRounds", rounds);
    settings.setValue("nAnonymizeCuriumAmount", coins);

    nDarksendRounds = rounds;
    nAnonymizeCuriumAmount = coins;    
}