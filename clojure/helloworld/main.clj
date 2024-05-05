(ns clojure.examples.hello (:gen-class))

(defn hel [] (println "Hello World"))
(hel)

(defn conkat [] (str "Hello" "World"))
(print (conkat))
