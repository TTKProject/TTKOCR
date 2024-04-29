#include "ocrapplicationmodule.h"
#include "ocrbackgroundmanager.h"

#include <QTimer>
#include <QPropertyAnimation>

OCRApplicationModule *OCRApplicationModule::m_instance = nullptr;

OCRApplicationModule::OCRApplicationModule(QObject *parent)
    : QObject(parent)
{
    m_instance = this;

    m_quitAnimation = new QPropertyAnimation(parent, "windowOpacity", this);

    G_BACKGROUND_PTR->setBackground(":/image/lb_background");
}

OCRApplicationModule::~OCRApplicationModule()
{
    Q_CLEANUP_RESOURCE(TTKOCR);
    delete m_quitAnimation;
}

OCRApplicationModule *OCRApplicationModule::instance()
{
    return m_instance;
}

void OCRApplicationModule::windowCloseAnimation()
{
    m_quitAnimation->stop();
    m_quitAnimation->setDuration(TTK_DN_S2MS / 2);
    m_quitAnimation->setStartValue(1.0f);
    m_quitAnimation->setEndValue(0.0f);
    m_quitAnimation->start();

    TTK_SIGNLE_SHOT(TTK_DN_S2MS, qApp, quit, TTK_SLOT);
}
