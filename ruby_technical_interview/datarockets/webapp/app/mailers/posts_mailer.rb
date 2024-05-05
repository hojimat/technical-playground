class PostsMailer < ApplicationMailer

  def confirm
    @user = User.first() # assuming only one recipient
    @post = params[:post]

    mail(to: "to@example.org", subject: "Post created successfully")
  end
end
