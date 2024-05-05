from flask import Flask, request, render_template
import pyshorteners as psh

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("myhome.html")

@app.route("/shorter")
def shorter():
    if request.method == 'GET':
        herurl = request.args['herurl']
        myurl = psh.Shortener().tinyurl.short(herurl)
        return {"original_url": herurl, "short_url": myurl}

if __name__=="__main_":
    app.run(debug=True)
