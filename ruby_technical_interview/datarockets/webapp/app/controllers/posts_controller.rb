class PostsController < ApplicationController
  def index
    @posts = Post.all
  end

  def new
    @post = Post.new
  end

  def create
    @post = Post.new(post_params)
    if @post.save
      # send an email
      PostsMailer.with(post: @post).confirm().deliver_later()

      # create a history record
      History.create(typeof: "postcreation", user: "#{User.first()}")

      # go back
      redirect_to "/posts", notice: "Post was successfully created"
    else
      render :new
    end
  end

  private

  def post_params
    params.require(:post).permit(:author, :title, :body)
  end

  
end
