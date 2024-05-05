from flask import Flask, request, render_template
import pyshorteners as psh


app = Flask(__name__)


@app.route("/")
def home():
    return render_template("myhome.html")


@app.route("/shorter")
def shorter():
    if request.method == "GET":
        herurl = request.args['myurl']
        myurl = psh.Shortener().tinyurl.short(herurl)
        return {'original_url': herurl, 'short_url':myurl}
    return "404"



if __name__=='__main__':
    app.run(debug=True)
