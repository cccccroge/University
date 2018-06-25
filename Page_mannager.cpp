#include "Page_mannager.h"

bool Page_mannager::run_page()
{
    if (this->next_page_type == START) {
        this->start_page->init();
        return this->start_page->run();
    }
    else if (this->next_page_type == PLAY) {
        this->play_page->init();
        return this->play_page->run();
    }
    else if (this->next_page_type == END_WIN) {
        this->end_page->init(0);
        return this->end_page->run();
    }
    else if (this->next_page_type == END_LOSE) {
        this->end_page->init(1);
        return this->end_page->run();
    }
    else {
        return false;
    }
}
