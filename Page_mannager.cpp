#include "Page_mannager.h"

bool Page_mannager::run_page()
{
    if (this->next_page_type == START) {
        return this->start_page->run();
    }
    else if (this->next_page_type == PLAY) {
        return this->play_page->run();
    }
    else if (this->next_page_type == END) {
        return this->end_page->run();
    }
}
