<% c++ #include "contents/%%CONTROLLER_NAME%%.h" %>
<% skin %>
<% view %%VIEW_NAME%% uses contents::%%CONTROLLER_NS%%::%%CONTENT_NAME%% extends master %>
<% template title() %><% gt "TODO TITLE" %><% end template %>


<% template body() %> 
    Edit Me %%CONTROLLER_NAME%% / %%CONTENT_NAME%%
<% end template %>



<% end view %>
<% end skin %>
