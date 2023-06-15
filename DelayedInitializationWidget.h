#pragma once

#include <QShowEvent>
#include <QWidget>

template <typename BASE>
class DelayedInitializationWidget : public BASE
{
public:
    using BASE::BASE;

protected:
    void setDirty()
    {
        m_dirty = true;
        if (BASE::isVisible())
            ensureInitialized();
    }
    void ensureInitialized() const
    {
        if (m_dirty) {
            m_dirty = false;
            const_cast<DelayedInitializationWidget *>(this)->initialize();
        }
    }
    virtual void initialize() = 0;
    void showEvent(QShowEvent *event) override
    {
        if (!event->spontaneous())
            ensureInitialized();
        BASE::showEvent(event);
    }

private:
    mutable bool m_dirty = true;
};
