/**
 *
 */
void %%CONTROLLER_NAME%%::%%ACTION_NAME%%() {

    contents::%%CONTROLLER_NS%%::%%CONTENT_NAME%% c;
    init_content(c);


    render("%%VIEW_NAME%%", c);
}

// %%%NEXT_ACTION_MARKER%%% , do not delete
