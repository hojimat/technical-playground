class Greeter
  attr_accessor :name
  def initialize(name="World")
    @name = name
  end
  def say_hi()
    puts "Hi, #{@name}!"
  end
  def say_bye()
    puts "Bye, #{@name}!"
  end
end

greeter = Greeter.new("Ravshan")
greeter.say_hi()
greeter.name = "Harry"
greeter.say_hi()
