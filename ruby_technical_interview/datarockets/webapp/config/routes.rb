Rails.application.routes.draw do
  root 'pages#home'
  get 'users/new',    to: 'users#new'
  post 'users',       to: 'users#create'
  get  'posts',       to: 'posts#index'
  get  'posts/new',   to: 'posts#new'
  post 'posts',       to: 'posts#create'
  get 'history',      to: 'history#index'
end
