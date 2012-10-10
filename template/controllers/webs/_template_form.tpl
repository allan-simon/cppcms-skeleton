/**
 *
 */
void %%CONTROLLER_NAME%%::%%FORM_NAME%%() {

    contents::%%CONTROLLER_NS%%::%%CONTENT_NAME%% c;
    init_content(c);


    render("%%VIEW_NAME%%", c);
}


/**
 *
 */
void %%CONTROLLER_NAME%%::%%FORM_TREAT_NAME%%() {

    forms::%%CONTROLLER_NS%%::%%FORM_STRUCT%% form;
    form.load(context());

    if (!form.validate()) {
        go_back_to_previous_page();
    }

}


// %%%NEXT_ACTION_MARKER%%% , do not delete
