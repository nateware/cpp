<%-- 
    Document   : index
    Created on : May 7, 2012, 9:01:00 PM
    Author     : nwiger
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
            // This is a scriptlet.  Notice that the "date"
            // variable we declare here is available in the
            // embedded expression later on.
            System.out.println( "Evaluating date now" );
            java.util.Date date = new java.util.Date();
        %>
        <h1>Hello World!</h1>
        <p>The time is now: <%= date %></p>
        <p><a href="?p=1">1</a> | <a href="?p=2">2</a> | <a href="?p=3">3</a></p>
        <%
            String p = request.getParameter("p");
            session.setAttribute("parm", p);
        %>
        parm=<%= p %> (<%= session.getAttribute("parm") %>)
    </body>
</html>
