class Student

    attr_accessor :name, :age, :subject

    def initialize(name,age,subject)
        @name = name
        @age = age
        @subject = subject
    end

end

s1 = Student.new("Ravshan", 18, "math")
puts s1.name()
puts s1.age()
puts s1;subject()