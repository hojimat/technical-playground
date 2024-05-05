class HistoryController < ApplicationController
  def index
    @history = History.all()
    @user = User.first() # assuming a single user for this project
  end
end
