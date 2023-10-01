def write_html():
    with open("gradient.html", "w") as file:
        file.write("<html>\n")
        file.write("<head>\n")
        file.write("<style>\n")

        file.write("body {\n")
        file.write("  background: linear-gradient(to bottom, white, black);\n")
        file.write("  height: 100vh;\n")
        file.write("  margin: 0;\n")
        file.write("  display: flex;\n")
        file.write("  align-items: center;\n")
        file.write("  justify-content: center;\n")
        file.write("}\n")

        file.write("</style>\n")
        file.write("</head>\n")

        file.write("<body>\n")
        file.write("</body>\n")

        file.write("</html>\n")

        return print("HTML-файл с градиентом создан: gradient.html")

test = write_html()
