class RenameHistories < ActiveRecord::Migration[7.0]
  def change
    rename_column :histories, :type, :typeof
  end
end
