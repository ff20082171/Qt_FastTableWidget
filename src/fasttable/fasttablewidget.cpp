#include "fasttablewidget.h"

FastTableWidget::FastTableWidget(QWidget *parent) :
    CustomFastTableWidget(parent)
{
    START_PROFILE;
    END_PROFILE("FastTableWidget::FastTableWidget(QWidget *parent)");
}

FastTableWidget::~FastTableWidget()
{
    START_PROFILE;
    END_PROFILE("FastTableWidget::~FastTableWidget()");
}

void FastTableWidget::paintEvent(QPaintEvent *event)
{
    START_FREQUENT_PROFILE;

    QPainter painter(viewport());

    int offsetX=-horizontalScrollBar()->value();
    int offsetY=-verticalScrollBar()->value();

    QSize areaSize=viewport()->size();

    if (mVisibleLeft>=0 && mVisibleTop>=0)
    {
        for (int i=mVisibleTop; i<=mVisibleBottom; ++i)
        {
            for (int j=mVisibleLeft; j<=mVisibleRight; ++j)
            {
                if (mCellMergeParentRow.at(i).at(j)>=0 && mCellMergeParentColumn.at(i).at(j)>=0)
                {
                    int spanX=mCellMergeX.at(i).at(j);
                    int spanY=mCellMergeY.at(i).at(j);

                    if (spanX>1 || spanY>1)
                    {
                        int aWidth=0;
                        int aHeight=0;

                        for (int g=0; g<spanX; g++)
                        {
                            aWidth+=mColumnWidths.at(j+g);
                        }

                        for (int g=0; g<spanY; g++)
                        {
                            aHeight+=mRowHeights.at(i+g);
                        }

                        if (
                            offsetX+mOffsetX.at(j)<=areaSize.width()
                            &&
                            offsetX+mOffsetX.at(j)>=-aWidth
                            &&
                            offsetY+mOffsetY.at(i)<=areaSize.height()
                            &&
                            offsetY+mOffsetY.at(i)>=-aHeight
                            &&
                            aWidth>0
                            &&
                            aHeight>0
                           )
                        {
                            paintCell(painter, offsetX+mOffsetX.at(j), offsetY+mOffsetY.at(i), aWidth, aHeight, i, j, DrawCell);
                        }
                    }
                }
                else
                {
                    if (
                        offsetX+mOffsetX.at(j)<=areaSize.width()
                        &&
                        offsetX+mOffsetX.at(j)>=-mColumnWidths.at(j)
                        &&
                        offsetY+mOffsetY.at(i)<=areaSize.height()
                        &&
                        offsetY+mOffsetY.at(i)>=-mRowHeights.at(i)
                        &&
                        mColumnWidths.at(j)>0
                        &&
                        mRowHeights.at(i)>0
                       )
                    {
                        paintCell(painter, offsetX+mOffsetX.at(j), offsetY+mOffsetY.at(i), mColumnWidths.at(j), mRowHeights.at(i), i, j, DrawCell);
                    }
                }
            }
        }
    }

    if (mHorizontalHeader_VisibleBottom>=0 && mVisibleLeft>=0)
    {
        for (int i=0; i<=mHorizontalHeader_VisibleBottom; ++i)
        {
            for (int j=mVisibleLeft; j<=mVisibleRight; ++j)
            {
                if (mHorizontalHeader_CellMergeParentRow.at(i).at(j)>=0 && mHorizontalHeader_CellMergeParentColumn.at(i).at(j)>=0)
                {
                    int spanX=mHorizontalHeader_CellMergeX.at(i).at(j);
                    int spanY=mHorizontalHeader_CellMergeY.at(i).at(j);

                    if (spanX>1 || spanY>1)
                    {
                        int aWidth=0;
                        int aHeight=0;

                        for (int g=0; g<spanX; g++)
                        {
                            aWidth+=mColumnWidths.at(j+g);
                        }

                        for (int g=0; g<spanY; g++)
                        {
                            aHeight+=mHorizontalHeader_RowHeights.at(i+g);
                        }

                        if (
                            offsetX+mOffsetX.at(j)<=areaSize.width()
                            &&
                            offsetX+mOffsetX.at(j)>=-aWidth
                            &&
                            mHorizontalHeader_OffsetY.at(i)<=areaSize.height()
                            &&
                            mHorizontalHeader_OffsetY.at(i)>=-aHeight
                            &&
                            aWidth>0
                            &&
                            aHeight>0
                           )
                        {
                            paintCell(painter, offsetX+mOffsetX.at(j), mHorizontalHeader_OffsetY.at(i), aWidth, aHeight, i, j, DrawHorizontalHeaderCell);
                        }
                    }
                }
                else
                {
                    if (
                        offsetX+mOffsetX.at(j)<=areaSize.width()
                        &&
                        offsetX+mOffsetX.at(j)>=-mColumnWidths.at(j)
                        &&
                        mHorizontalHeader_OffsetY.at(i)<=areaSize.height()
                        &&
                        mHorizontalHeader_OffsetY.at(i)>=-mHorizontalHeader_RowHeights.at(i)
                        &&
                        mColumnWidths.at(j)>0
                        &&
                        mHorizontalHeader_RowHeights.at(i)>0
                       )
                    {
                        paintCell(painter, offsetX+mOffsetX.at(j), mHorizontalHeader_OffsetY.at(i), mColumnWidths.at(j), mHorizontalHeader_RowHeights.at(i), i, j, DrawHorizontalHeaderCell);
                    }
                }
            }
        }
    }

    if (mVerticalHeader_VisibleRight>=0 && mVisibleTop>=0)
    {
        for (int i=mVisibleTop; i<=mVisibleBottom; ++i)
        {
            for (int j=0; j<=mVerticalHeader_VisibleRight; ++j)
            {
                if (mVerticalHeader_CellMergeParentRow.at(i).at(j)>=0 && mVerticalHeader_CellMergeParentColumn.at(i).at(j)>=0)
                {
                    int spanX=mVerticalHeader_CellMergeX.at(i).at(j);
                    int spanY=mVerticalHeader_CellMergeY.at(i).at(j);

                    if (spanX>1 || spanY>1)
                    {
                        int aWidth=0;
                        int aHeight=0;

                        for (int g=0; g<spanX; g++)
                        {
                            aWidth+=mVerticalHeader_ColumnWidths.at(j+g);
                        }

                        for (int g=0; g<spanY; g++)
                        {
                            aHeight+=mRowHeights.at(i+g);
                        }

                        if (
                            mVerticalHeader_OffsetX.at(j)<=areaSize.width()
                            &&
                            mVerticalHeader_OffsetX.at(j)>=-aWidth
                            &&
                            offsetY+mOffsetY.at(i)<=areaSize.height()
                            &&
                            offsetY+mOffsetY.at(i)>=-aHeight
                            &&
                            aWidth>0
                            &&
                            aHeight>0
                           )
                        {
                            paintCell(painter, mVerticalHeader_OffsetX.at(j), offsetY+mOffsetY.at(i), aWidth, aHeight, i, j, DrawVerticalHeaderCell);
                        }
                    }
                }
                else
                {
                    if (
                        mVerticalHeader_OffsetX.at(j)<=areaSize.width()
                        &&
                        mVerticalHeader_OffsetX.at(j)>=-mVerticalHeader_ColumnWidths.at(j)
                        &&
                        offsetY+mOffsetY.at(i)<=areaSize.height()
                        &&
                        offsetY+mOffsetY.at(i)>=-mRowHeights.at(i)
                        &&
                        mVerticalHeader_ColumnWidths.at(j)>0
                        &&
                        mRowHeights.at(i)>0
                       )
                    {
                        paintCell(painter, mVerticalHeader_OffsetX.at(j), offsetY+mOffsetY.at(i), mVerticalHeader_ColumnWidths.at(j), mRowHeights.at(i), i, j, DrawVerticalHeaderCell);
                    }
                }
            }
        }
    }

    if (mVerticalHeader_VisibleRight>=0 && mHorizontalHeader_VisibleBottom>=0 && mVerticalHeader_TotalWidth>=0 && mHorizontalHeader_TotalHeight>=0)
    {
        paintCell(painter, 0, 0, mVerticalHeader_TotalWidth, mHorizontalHeader_TotalHeight, -1, -1, DrawTopLeftCorner);
    }

    END_FREQUENT_PROFILE("void FastTableWidget::paintEvent(QPaintEvent *event)");
}

void FastTableWidget::paintCell(QPainter &painter, const int x, const int y, const int width, const int height, const int row, const int column, const DrawComponent drawComponent)
{
    START_FREQUENT_PROFILE;

    QColor  *aGridColor;
    QBrush  *aBackgroundBrush;
    QColor  *aTextColor;
    QString *aText;
    QString aVerticalText;
    QFont   *aFont;
    QFont   aTextFont;
    int     textFlags;

    switch (drawComponent)
    {
        case DrawCell:
        {
            aGridColor=&mGridColor;

            if (mSelectedCells.at(row).at(column))
            {
                aBackgroundBrush=&mSelectionBrush;
                aTextColor=&mSelectionTextColor;
            }
            else
            {
                aBackgroundBrush=mBackgroundBrushes.at(row).at(column);

                if (aBackgroundBrush==0)
                {
                    aBackgroundBrush=&mDefaultBackgroundBrush;
                }

                aTextColor=mForegroundColors.at(row).at(column);

                if (aTextColor==0)
                {
                    aTextColor=&mDefaultForegroundColor;
                }
            }

            aText=&mData[row][column];

            aFont=mCellFonts.at(row).at(column);

            if (aFont==0)
            {
                aTextFont=font();
                aFont=&aTextFont;
            }

            textFlags=mCellTextFlags.at(row).at(column);
        }
        break;
        case DrawHorizontalHeaderCell:
        {
            aGridColor=&mHorizontalHeader_GridColor;

            aBackgroundBrush=mHorizontalHeader_BackgroundBrushes.at(row).at(column);

            if (aBackgroundBrush==0)
            {
                aBackgroundBrush=&mHorizontalHeader_DefaultBackgroundBrush;
            }

            aTextColor=mHorizontalHeader_ForegroundColors.at(row).at(column);

            if (aTextColor==0)
            {
                aTextColor=&mHorizontalHeader_DefaultForegroundColor;
            }

            aText=&mHorizontalHeader_Data[row][column];

            aFont=mHorizontalHeader_CellFonts.at(row).at(column);

            if (aFont==0)
            {
                aTextFont=font();
                aFont=&aTextFont;
            }

            bool good=false;

            for (int i=0; i<mHorizontalHeader_CellMergeX.at(row).at(column); i++)
            {
                if (mHorizontalHeader_SelectedColumns.at(column+i))
                {
                    good=true;
                    break;
                }
            }

            if (good)
            {
                if (aFont!=&aTextFont)
                {
                    aTextFont=*aFont;
                    aFont=&aTextFont;
                }

                aBackgroundBrush=&mHorizontalHeader_DefaultBackgroundBrush;

                aFont->setPointSize(aFont->pointSize()+1);
                aFont->setBold(true);
            }

            textFlags=mHorizontalHeader_CellTextFlags.at(row).at(column);
        }
        break;
        case DrawVerticalHeaderCell:
        {
            aGridColor=&mVerticalHeader_GridColor;

            aBackgroundBrush=mVerticalHeader_BackgroundBrushes.at(row).at(column);

            if (aBackgroundBrush==0)
            {
                aBackgroundBrush=&mVerticalHeader_DefaultBackgroundBrush;
            }

            aTextColor=mVerticalHeader_ForegroundColors.at(row).at(column);

            if (aTextColor==0)
            {
                aTextColor=&mVerticalHeader_DefaultForegroundColor;
            }

            aText=&mVerticalHeader_Data[row][column];

            if (*aText=="")
            {
                aVerticalText=QString::number(row+1);
                aText=&aVerticalText;
            }

            aFont=mVerticalHeader_CellFonts.at(row).at(column);

            if (aFont==0)
            {
                aTextFont=font();
                aFont=&aTextFont;
            }

            bool good=false;

            for (int i=0; i<mVerticalHeader_CellMergeY.at(row).at(column); i++)
            {
                if (mVerticalHeader_SelectedRows.at(row+i))
                {
                    good=true;
                    break;
                }
            }

            if (good)
            {
                if (aFont!=&aTextFont)
                {
                    aTextFont=*aFont;
                    aFont=&aTextFont;
                }

                aFont->setPointSize(aFont->pointSize()+1);
                aFont->setBold(true);
            }

            textFlags=mVerticalHeader_CellTextFlags.at(row).at(column);
        }
        break;
        case DrawTopLeftCorner:
        {
            aGridColor=&mHorizontalHeader_GridColor;
            aBackgroundBrush=&mHorizontalHeader_DefaultBackgroundBrush;
            aTextColor=0;
            aText=0;
            aFont=0;
            textFlags=0;
        }
        break;
        default:
        {
            aGridColor=0;
            aBackgroundBrush=0;
            aTextColor=0;
            aText=0;
            aFont=0;
            textFlags=0;
        }
        break;
    }

    CustomFastTableWidget::paintCell(painter, x ,y, width, height, row, column, drawComponent, aGridColor, aBackgroundBrush, aTextColor, aText, aFont, textFlags);

    END_FREQUENT_PROFILE("void FastTableWidget::paintCell(QPainter &painter, const int x, const int y, const int row, const int column)");
}

void FastTableWidget::updateVisibleRange()
{
    START_PROFILE;

    CustomFastTableWidget::updateVisibleRange();

    int originalLeft=mVisibleLeft;
    int originalTop=mVisibleTop;

    if (originalLeft>=0)
    {
        for (int i=0; i<mRowCount; i++)
        {
            int parentColumn=mCellMergeParentColumn.at(i).at(originalLeft);

            if (parentColumn>=0 &&parentColumn<mVisibleLeft)
            {
                mVisibleLeft=parentColumn;
            }
        }

        for (int i=0; i<mHorizontalHeader_RowCount; i++)
        {
            int parentColumn=mHorizontalHeader_CellMergeParentColumn.at(i).at(originalLeft);

            if (parentColumn>=0 &&parentColumn<mVisibleLeft)
            {
                mVisibleLeft=parentColumn;
            }
        }
    }

    if (originalTop>=0)
    {
        for (int i=0; i<mColumnCount; i++)
        {
            int parentRow=mCellMergeParentRow.at(originalTop).at(i);

            if (parentRow>=0 && parentRow<mVisibleTop)
            {
                mVisibleTop=parentRow;
            }
        }

        for (int i=0; i<mVerticalHeader_ColumnCount; i++)
        {
            int parentRow=mVerticalHeader_CellMergeParentRow.at(originalTop).at(i);

            if (parentRow>=0 && parentRow<mVisibleTop)
            {
                mVisibleTop=parentRow;
            }
        }
    }

    END_PROFILE("void FastTableWidget::updateVisibleRange()");
}

void FastTableWidget::clearTable()
{
    START_PROFILE;

    resetBackgroundBrushes();
    resetForegroundColors();
    resetFonts();

    horizontalHeader_ResetBackgroundBrushes();
    horizontalHeader_ResetForegroundColors();
    horizontalHeader_ResetFonts();

    verticalHeader_ResetBackgroundBrushes();
    verticalHeader_ResetForegroundColors();
    verticalHeader_ResetFonts();

    mBackgroundBrushes.clear();
    mForegroundColors.clear();
    mCellFonts.clear();
    mCellTextFlags.clear();
    mCellMergeX.clear();
    mCellMergeY.clear();
    mCellMergeParentRow.clear();
    mCellMergeParentColumn.clear();

    mHorizontalHeader_BackgroundBrushes.clear();
    mHorizontalHeader_ForegroundColors.clear();
    mHorizontalHeader_CellFonts.clear();
    mHorizontalHeader_CellTextFlags.clear();
    mHorizontalHeader_CellMergeX.clear();
    mHorizontalHeader_CellMergeY.clear();
    mHorizontalHeader_CellMergeParentRow.clear();
    mHorizontalHeader_CellMergeParentColumn.clear();

    mVerticalHeader_BackgroundBrushes.clear();
    mVerticalHeader_ForegroundColors.clear();
    mVerticalHeader_CellFonts.clear();
    mVerticalHeader_CellTextFlags.clear();
    mVerticalHeader_CellMergeX.clear();
    mVerticalHeader_CellMergeY.clear();
    mVerticalHeader_CellMergeParentRow.clear();
    mVerticalHeader_CellMergeParentColumn.clear();

    CustomFastTableWidget::clearTable();

    END_PROFILE("void FastTableWidget::clearTable()");
}

void FastTableWidget::resetBackgroundBrushes()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mBackgroundBrushes.at(i).at(j))
            {
                delete mBackgroundBrushes.at(i).at(j);
                mBackgroundBrushes[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::resetBackgroundBrushes()");
}

void FastTableWidget::resetForegroundColors()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mForegroundColors.at(i).at(j))
            {
                delete mForegroundColors.at(i).at(j);
                mForegroundColors[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::resetForegroundColors()");
}

void FastTableWidget::resetFonts()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mCellFonts.at(i).at(j))
            {
                delete mCellFonts.at(i).at(j);
                mCellFonts[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::resetFonts()");
}

void FastTableWidget::resetCellTextFlags()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            mCellTextFlags[i][j]=FASTTABLE_DEFAULT_TEXT_FLAG;
        }
    }

    END_PROFILE("void FastTableWidget::resetCellTextFlags()");
}

void FastTableWidget::horizontalHeader_ResetBackgroundBrushes()
{
    START_PROFILE;

    for (int i=0; i<mHorizontalHeader_RowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mHorizontalHeader_BackgroundBrushes.at(i).at(j))
            {
                delete mHorizontalHeader_BackgroundBrushes.at(i).at(j);
                mHorizontalHeader_BackgroundBrushes[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetBackgroundBrushes()");
}

void FastTableWidget::horizontalHeader_ResetForegroundColors()
{
    START_PROFILE;

    for (int i=0; i<mHorizontalHeader_RowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mHorizontalHeader_ForegroundColors.at(i).at(j))
            {
                delete mHorizontalHeader_ForegroundColors.at(i).at(j);
                mHorizontalHeader_ForegroundColors[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetForegroundColors()");
}

void FastTableWidget::horizontalHeader_ResetFonts()
{
    START_PROFILE;

    for (int i=0; i<mHorizontalHeader_RowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            if (mHorizontalHeader_CellFonts.at(i).at(j))
            {
                delete mHorizontalHeader_CellFonts.at(i).at(j);
                mHorizontalHeader_CellFonts[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetFonts()");
}

void FastTableWidget::horizontalHeader_ResetCellTextFlags()
{
    START_PROFILE;

    for (int i=0; i<mHorizontalHeader_RowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            mHorizontalHeader_CellTextFlags[i][j]=FASTTABLE_HEADER_DEFAULT_TEXT_FLAG;
        }
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetCellTextFlags()");
}

void FastTableWidget::verticalHeader_ResetBackgroundBrushes()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mVerticalHeader_ColumnCount; ++j)
        {
            if (mVerticalHeader_BackgroundBrushes.at(i).at(j))
            {
                delete mVerticalHeader_BackgroundBrushes.at(i).at(j);
                mVerticalHeader_BackgroundBrushes[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetBackgroundBrushes()");
}

void FastTableWidget::verticalHeader_ResetForegroundColors()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mVerticalHeader_ColumnCount; ++j)
        {
            if (mVerticalHeader_ForegroundColors.at(i).at(j))
            {
                delete mVerticalHeader_ForegroundColors.at(i).at(j);
                mVerticalHeader_ForegroundColors[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetForegroundColors()");
}

void FastTableWidget::verticalHeader_ResetFonts()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mVerticalHeader_ColumnCount; ++j)
        {
            if (mVerticalHeader_CellFonts.at(i).at(j))
            {
                delete mVerticalHeader_CellFonts.at(i).at(j);
                mVerticalHeader_CellFonts[i][j]=0;
            }
        }
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetFonts()");
}

void FastTableWidget::verticalHeader_ResetCellTextFlags()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mVerticalHeader_ColumnCount; ++j)
        {
            mVerticalHeader_CellTextFlags[i][j]=FASTTABLE_DEFAULT_TEXT_FLAG;
        }
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetCellTextFlags()");
}

void FastTableWidget::resetBackgroundBrush(const int row, const int column)
{
    START_PROFILE;

    if (mBackgroundBrushes.at(row).at(column))
    {
        delete mBackgroundBrushes.at(row).at(column);
        mBackgroundBrushes[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::resetBackgroundBrush(const int row, const int column)");
}

void FastTableWidget::resetForegroundColor(const int row, const int column)
{
    START_PROFILE;

    if (mForegroundColors.at(row).at(column))
    {
        delete mForegroundColors.at(row).at(column);
        mForegroundColors[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::resetForegroundColor(const int row, const int column)");
}

void FastTableWidget::resetFont(const int row, const int column)
{
    START_PROFILE;

    if (mCellFonts.at(row).at(column))
    {
        delete mCellFonts.at(row).at(column);
        mCellFonts[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::resetFont(const int row, const int column)");
}

void FastTableWidget::resetCellTextFlag(const int row, const int column)
{
    START_PROFILE;

    mCellTextFlags[row][column]=FASTTABLE_DEFAULT_TEXT_FLAG;

    END_PROFILE("void FastTableWidget::resetCellTextFlag(const int row, const int column)");
}

void FastTableWidget::horizontalHeader_ResetBackgroundBrush(const int row, const int column)
{
    START_PROFILE;

    if (mHorizontalHeader_BackgroundBrushes.at(row).at(column))
    {
        delete mHorizontalHeader_BackgroundBrushes.at(row).at(column);
        mHorizontalHeader_BackgroundBrushes[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetBackgroundBrush(const int row, const int column)");
}

void FastTableWidget::horizontalHeader_ResetForegroundColor(const int row, const int column)
{
    START_PROFILE;

    if (mHorizontalHeader_ForegroundColors.at(row).at(column))
    {
        delete mHorizontalHeader_ForegroundColors.at(row).at(column);
        mHorizontalHeader_ForegroundColors[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetForegroundColor(const int row, const int column)");
}

void FastTableWidget::horizontalHeader_ResetFont(const int row, const int column)
{
    START_PROFILE;

    if (mHorizontalHeader_CellFonts.at(row).at(column))
    {
        delete mHorizontalHeader_CellFonts.at(row).at(column);
        mHorizontalHeader_CellFonts[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetFont(const int row, const int column)");
}

void FastTableWidget::horizontalHeader_ResetCellTextFlag(const int row, const int column)
{
    START_PROFILE;

    mHorizontalHeader_CellTextFlags[row][column]=FASTTABLE_HEADER_DEFAULT_TEXT_FLAG;

    END_PROFILE("void FastTableWidget::horizontalHeader_ResetCellTextFlag(const int row, const int column)");
}

void FastTableWidget::verticalHeader_ResetBackgroundBrush(const int row, const int column)
{
    START_PROFILE;

    if (mVerticalHeader_BackgroundBrushes.at(row).at(column))
    {
        delete mVerticalHeader_BackgroundBrushes.at(row).at(column);
        mVerticalHeader_BackgroundBrushes[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetBackgroundBrush(const int row, const int column)");
}

void FastTableWidget::verticalHeader_ResetForegroundColor(const int row, const int column)
{
    START_PROFILE;

    if (mVerticalHeader_ForegroundColors.at(row).at(column))
    {
        delete mVerticalHeader_ForegroundColors.at(row).at(column);
        mVerticalHeader_ForegroundColors[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetForegroundColor(const int row, const int column)");
}

void FastTableWidget::verticalHeader_ResetFont(const int row, const int column)
{
    START_PROFILE;

    if (mVerticalHeader_CellFonts.at(row).at(column))
    {
        delete mVerticalHeader_CellFonts.at(row).at(column);
        mVerticalHeader_CellFonts[row][column]=0;
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ResetFont(const int row, const int column)");
}

void FastTableWidget::verticalHeader_ResetCellTextFlag(const int row, const int column)
{
    START_PROFILE;

    mVerticalHeader_CellTextFlags[row][column]=FASTTABLE_DEFAULT_TEXT_FLAG;

    END_PROFILE("void FastTableWidget::verticalHeader_ResetCellTextFlag(const int row, const int column)");
}

void FastTableWidget::insertRow(int row)
{
    START_PROFILE;

    CustomFastTableWidget::insertRow(row);

    QList<QBrush *> aNewRowBrush;
    QList<QColor *> aNewRowColor;
    QList<QFont *> aNewRowFont;
    QList<int> aNewRowint;
    QList<quint16> aNewRowqint16;

    mBackgroundBrushes.insert(row, aNewRowBrush);
    mForegroundColors.insert(row, aNewRowColor);
    mCellFonts.insert(row, aNewRowFont);
    mCellTextFlags.insert(row, aNewRowint);
    mCellMergeX.insert(row, aNewRowqint16);
    mCellMergeY.insert(row, aNewRowqint16);
    mCellMergeParentRow.insert(row, aNewRowint);
    mCellMergeParentColumn.insert(row, aNewRowint);

    mVerticalHeader_BackgroundBrushes.insert(row, aNewRowBrush);
    mVerticalHeader_ForegroundColors.insert(row, aNewRowColor);
    mVerticalHeader_CellFonts.insert(row, aNewRowFont);
    mVerticalHeader_CellTextFlags.insert(row, aNewRowint);
    mVerticalHeader_CellMergeX.insert(row, aNewRowqint16);
    mVerticalHeader_CellMergeY.insert(row, aNewRowqint16);
    mVerticalHeader_CellMergeParentRow.insert(row, aNewRowint);
    mVerticalHeader_CellMergeParentColumn.insert(row, aNewRowint);

    for (int i=0; i<mColumnCount; ++i)
    {
        mBackgroundBrushes[row].append(0);
        mForegroundColors[row].append(0);
        mCellFonts[row].append(0);
        mCellTextFlags[row].append(FASTTABLE_DEFAULT_TEXT_FLAG);
        mCellMergeX[row].append(1);
        mCellMergeY[row].append(1);
        mCellMergeParentRow[row].append(-1);
        mCellMergeParentColumn[row].append(-1);
    }

    for (int i=0; i<mVerticalHeader_ColumnCount; ++i)
    {
        mVerticalHeader_BackgroundBrushes[row].append(0);
        mVerticalHeader_ForegroundColors[row].append(0);
        mVerticalHeader_CellFonts[row].append(0);
        mVerticalHeader_CellTextFlags[row].append(FASTTABLE_DEFAULT_TEXT_FLAG);
        mVerticalHeader_CellMergeX[row].append(1);
        mVerticalHeader_CellMergeY[row].append(1);
        mVerticalHeader_CellMergeParentRow[row].append(-1);
        mVerticalHeader_CellMergeParentColumn[row].append(-1);
    }

    END_PROFILE("void FastTableWidget::insertRow(int row)");
}

void FastTableWidget::deleteRow(int row)
{
    START_PROFILE;

    for (int i=0; i<mColumnCount; ++i)
    {
        if (mBackgroundBrushes.at(row).at(i))
        {
            delete mBackgroundBrushes.at(row).at(i);
        }

        if (mForegroundColors.at(row).at(i))
        {
            delete mForegroundColors.at(row).at(i);
        }

        if (mCellFonts.at(row).at(i))
        {
            delete mCellFonts.at(row).at(i);
        }
    }

    for (int i=0; i<mVerticalHeader_ColumnCount; ++i)
    {
        if (mVerticalHeader_BackgroundBrushes.at(row).at(i))
        {
            delete mVerticalHeader_BackgroundBrushes.at(row).at(i);
        }

        if (mVerticalHeader_ForegroundColors.at(row).at(i))
        {
            delete mVerticalHeader_ForegroundColors.at(row).at(i);
        }

        if (mVerticalHeader_CellFonts.at(row).at(i))
        {
            delete mVerticalHeader_CellFonts.at(row).at(i);
        }
    }

    mBackgroundBrushes.removeAt(row);
    mForegroundColors.removeAt(row);
    mCellFonts.removeAt(row);
    mCellTextFlags.removeAt(row);
    mCellMergeX.removeAt(row);
    mCellMergeY.removeAt(row);
    mCellMergeParentRow.removeAt(row);
    mCellMergeParentColumn.removeAt(row);

    mVerticalHeader_BackgroundBrushes.removeAt(row);
    mVerticalHeader_ForegroundColors.removeAt(row);
    mVerticalHeader_CellFonts.removeAt(row);
    mVerticalHeader_CellTextFlags.removeAt(row);
    mVerticalHeader_CellMergeX.removeAt(row);
    mVerticalHeader_CellMergeY.removeAt(row);
    mVerticalHeader_CellMergeParentRow.removeAt(row);
    mVerticalHeader_CellMergeParentColumn.removeAt(row);

    CustomFastTableWidget::deleteRow(row);

    END_PROFILE("void FastTableWidget::deleteRow(int row)");
}

void FastTableWidget::insertColumn(int column)
{
    START_PROFILE;

    CustomFastTableWidget::insertColumn(column);

    for (int i=0; i<mData.length(); ++i)
    {
        mBackgroundBrushes[i].insert(column, 0);
        mForegroundColors[i].insert(column, 0);
        mCellFonts[i].insert(column, 0);
        mCellTextFlags[i].insert(column, FASTTABLE_DEFAULT_TEXT_FLAG);
        mCellMergeX[i].insert(column, 1);
        mCellMergeY[i].insert(column, 1);
        mCellMergeParentRow[i].insert(column, -1);
        mCellMergeParentColumn[i].insert(column, -1);
    }

    for (int i=0; i<mHorizontalHeader_Data.length(); ++i)
    {
        mHorizontalHeader_BackgroundBrushes[i].insert(column, 0);
        mHorizontalHeader_ForegroundColors[i].insert(column, 0);
        mHorizontalHeader_CellFonts[i].insert(column, 0);
        mHorizontalHeader_CellTextFlags[i].insert(column, FASTTABLE_HEADER_DEFAULT_TEXT_FLAG);
        mHorizontalHeader_CellMergeX[i].insert(column, 1);
        mHorizontalHeader_CellMergeY[i].insert(column, 1);
        mHorizontalHeader_CellMergeParentRow[i].insert(column, -1);
        mHorizontalHeader_CellMergeParentColumn[i].insert(column, -1);
    }

    END_PROFILE("void FastTableWidget::insertColumn(int column)");
}

void FastTableWidget::deleteColumn(int column)
{
    START_PROFILE;

    for (int i=0; i<mData.length(); ++i)
    {
        if (mBackgroundBrushes.at(i).at(column))
        {
            delete mBackgroundBrushes.at(i).at(column);
        }

        if (mForegroundColors.at(i).at(column))
        {
            delete mForegroundColors.at(i).at(column);
        }

        if (mCellFonts.at(i).at(column))
        {
            delete mCellFonts.at(i).at(column);
        }

        mBackgroundBrushes[i].removeAt(column);
        mForegroundColors[i].removeAt(column);
        mCellFonts[i].removeAt(column);
        mCellTextFlags[i].removeAt(column);
        mCellMergeX[i].removeAt(column);
        mCellMergeY[i].removeAt(column);
        mCellMergeParentRow[i].removeAt(column);
        mCellMergeParentColumn[i].removeAt(column);
    }

    for (int i=0; i<mHorizontalHeader_Data.length(); ++i)
    {
        if (mHorizontalHeader_BackgroundBrushes.at(i).at(column))
        {
            delete mHorizontalHeader_BackgroundBrushes.at(i).at(column);
        }

        if (mHorizontalHeader_ForegroundColors.at(i).at(column))
        {
            delete mHorizontalHeader_ForegroundColors.at(i).at(column);
        }

        if (mHorizontalHeader_CellFonts.at(i).at(column))
        {
            delete mHorizontalHeader_CellFonts.at(i).at(column);
        }

        mHorizontalHeader_BackgroundBrushes[i].removeAt(column);
        mHorizontalHeader_ForegroundColors[i].removeAt(column);
        mHorizontalHeader_CellFonts[i].removeAt(column);
        mHorizontalHeader_CellTextFlags[i].removeAt(column);
        mHorizontalHeader_CellMergeX[i].removeAt(column);
        mHorizontalHeader_CellMergeY[i].removeAt(column);
        mHorizontalHeader_CellMergeParentRow[i].removeAt(column);
        mHorizontalHeader_CellMergeParentColumn[i].removeAt(column);
    }

    CustomFastTableWidget::deleteColumn(column);

    END_PROFILE("void FastTableWidget::deleteColumn(int column)");
}

void FastTableWidget::horizontalHeader_InsertRow(int row)
{
    START_PROFILE;

    CustomFastTableWidget::horizontalHeader_InsertRow(row);

    QList<QBrush *> aNewRowBrush;
    QList<QColor *> aNewRowColor;
    QList<QFont *> aNewRowFont;
    QList<int> aNewRowint;
    QList<quint16> aNewRowqint16;

    mHorizontalHeader_BackgroundBrushes.insert(row, aNewRowBrush);
    mHorizontalHeader_ForegroundColors.insert(row, aNewRowColor);
    mHorizontalHeader_CellFonts.insert(row, aNewRowFont);
    mHorizontalHeader_CellTextFlags.insert(row, aNewRowint);
    mHorizontalHeader_CellMergeX.insert(row, aNewRowqint16);
    mHorizontalHeader_CellMergeY.insert(row, aNewRowqint16);
    mHorizontalHeader_CellMergeParentRow.insert(row, aNewRowint);
    mHorizontalHeader_CellMergeParentColumn.insert(row, aNewRowint);

    for (int i=0; i<mColumnCount; ++i)
    {
        mHorizontalHeader_BackgroundBrushes[row].append(0);
        mHorizontalHeader_ForegroundColors[row].append(0);
        mHorizontalHeader_CellFonts[row].append(0);
        mHorizontalHeader_CellTextFlags[row].append(FASTTABLE_HEADER_DEFAULT_TEXT_FLAG);
        mHorizontalHeader_CellMergeX[row].append(1);
        mHorizontalHeader_CellMergeY[row].append(1);
        mHorizontalHeader_CellMergeParentRow[row].append(-1);
        mHorizontalHeader_CellMergeParentColumn[row].append(-1);
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_InsertRow(int row)");
}

void FastTableWidget::horizontalHeader_DeleteRow(int row)
{
    START_PROFILE;

    for (int i=0; i<mColumnCount; ++i)
    {
        if (mHorizontalHeader_BackgroundBrushes.at(row).at(i))
        {
            delete mHorizontalHeader_BackgroundBrushes.at(row).at(i);
        }

        if (mHorizontalHeader_ForegroundColors.at(row).at(i))
        {
            delete mHorizontalHeader_ForegroundColors.at(row).at(i);
        }

        if (mHorizontalHeader_CellFonts.at(row).at(i))
        {
            delete mHorizontalHeader_CellFonts.at(row).at(i);
        }
    }

    mHorizontalHeader_BackgroundBrushes.removeAt(row);
    mHorizontalHeader_ForegroundColors.removeAt(row);
    mHorizontalHeader_CellFonts.removeAt(row);
    mHorizontalHeader_CellTextFlags.removeAt(row);
    mHorizontalHeader_CellMergeX.removeAt(row);
    mHorizontalHeader_CellMergeY.removeAt(row);
    mHorizontalHeader_CellMergeParentRow.removeAt(row);
    mHorizontalHeader_CellMergeParentColumn.removeAt(row);

    CustomFastTableWidget::horizontalHeader_DeleteRow(row);

    END_PROFILE("void FastTableWidget::horizontalHeader_DeleteRow(int row)");
}

void FastTableWidget::verticalHeader_InsertColumn(int column)
{
    START_PROFILE;

    CustomFastTableWidget::verticalHeader_InsertColumn(column);

    for (int i=0; i<mData.length(); ++i)
    {
        mVerticalHeader_BackgroundBrushes[i].insert(column, 0);
        mVerticalHeader_ForegroundColors[i].insert(column, 0);
        mVerticalHeader_CellFonts[i].insert(column, 0);
        mVerticalHeader_CellTextFlags[i].insert(column, FASTTABLE_DEFAULT_TEXT_FLAG);
        mVerticalHeader_CellMergeX[i].insert(column, 1);
        mVerticalHeader_CellMergeY[i].insert(column, 1);
        mVerticalHeader_CellMergeParentRow[i].insert(column, -1);
        mVerticalHeader_CellMergeParentColumn[i].insert(column, -1);
    }

    END_PROFILE("void FastTableWidget::verticalHeader_InsertColumn(int column)");
}

void FastTableWidget::verticalHeader_DeleteColumn(int column)
{
    START_PROFILE;

    for (int i=0; i<mData.length(); ++i)
    {
        if (mVerticalHeader_BackgroundBrushes.at(i).at(column))
        {
            delete mVerticalHeader_BackgroundBrushes.at(i).at(column);
        }

        if (mVerticalHeader_ForegroundColors.at(i).at(column))
        {
            delete mVerticalHeader_ForegroundColors.at(i).at(column);
        }

        if (mVerticalHeader_CellFonts.at(i).at(column))
        {
            delete mVerticalHeader_CellFonts.at(i).at(column);
        }

        mVerticalHeader_BackgroundBrushes[i].removeAt(column);
        mVerticalHeader_ForegroundColors[i].removeAt(column);
        mVerticalHeader_CellFonts[i].removeAt(column);
        mVerticalHeader_CellTextFlags[i].removeAt(column);
        mVerticalHeader_CellMergeX[i].removeAt(column);
        mVerticalHeader_CellMergeY[i].removeAt(column);
        mVerticalHeader_CellMergeParentRow[i].removeAt(column);
        mVerticalHeader_CellMergeParentColumn[i].removeAt(column);
    }

    CustomFastTableWidget::verticalHeader_DeleteColumn(column);

    END_PROFILE("void FastTableWidget::verticalHeader_DeleteColumn(int column)");
}

QBrush FastTableWidget::backgroundBrush(const int row, const int column)
{
    START_PROFILE;

    QBrush *aBrush=mBackgroundBrushes.at(row).at(column);

    if (aBrush==0)
    {
        aBrush=&mDefaultBackgroundBrush;
    }

    END_PROFILE("QBrush FastTableWidget::backgroundBrush(const int row, const int column)");

    return *aBrush;
}

void FastTableWidget::setBackgroundBrush(const int row, const int column, const QBrush brush)
{
    START_PROFILE;

    if (mBackgroundBrushes.at(row).at(column))
    {
        *mBackgroundBrushes[row][column]=brush;
    }
    else
    {
        mBackgroundBrushes[row][column]=new QBrush(brush);
    }

    END_PROFILE("void FastTableWidget::setBackgroundBrush(const int row, const int column, const QBrush brush)");
}

QBrush FastTableWidget::horizontalHeader_BackgroundBrush(const int row, const int column)
{
    START_PROFILE;

    QBrush *aBrush=mHorizontalHeader_BackgroundBrushes.at(row).at(column);

    if (aBrush==0)
    {
        aBrush=&mHorizontalHeader_DefaultBackgroundBrush;
    }

    END_PROFILE("QBrush FastTableWidget::horizontalHeader_BackgroundBrush(const int row, const int column)");

    return *aBrush;
}

void FastTableWidget::horizontalHeader_SetBackgroundBrush(const int row, const int column, const QBrush brush)
{
    START_PROFILE;

    if (mHorizontalHeader_BackgroundBrushes.at(row).at(column))
    {
        *mHorizontalHeader_BackgroundBrushes[row][column]=brush;
    }
    else
    {
        mHorizontalHeader_BackgroundBrushes[row][column]=new QBrush(brush);
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_SetBackgroundBrush(const int row, const int column, const QBrush brush)");
}

QBrush FastTableWidget::verticalHeader_BackgroundBrush(const int row, const int column)
{
    START_PROFILE;

    QBrush *aBrush=mVerticalHeader_BackgroundBrushes.at(row).at(column);

    if (aBrush==0)
    {
        aBrush=&mVerticalHeader_DefaultBackgroundBrush;
    }

    END_PROFILE("QBrush FastTableWidget::verticalHeader_BackgroundBrush(const int row, const int column)");

    return *aBrush;
}

void FastTableWidget::verticalHeader_SetBackgroundBrush(const int row, const int column, const QBrush brush)
{
    START_PROFILE;

    if (mVerticalHeader_BackgroundBrushes.at(row).at(column))
    {
        *mVerticalHeader_BackgroundBrushes[row][column]=brush;
    }
    else
    {
        mVerticalHeader_BackgroundBrushes[row][column]=new QBrush(brush);
    }

    END_PROFILE("void FastTableWidget::verticalHeader_SetBackgroundBrush(const int row, const int column, const QBrush brush)");
}

QColor FastTableWidget::foregroundColor(const int row, const int column)
{
    START_PROFILE;

    QColor *aColor=mForegroundColors.at(row).at(column);

    if (aColor==0)
    {
        aColor=&mDefaultForegroundColor;
    }

    END_PROFILE("QColor FastTableWidget::foregroundColor(const int row, const int column)");

    return *aColor;
}

void FastTableWidget::setForegroundColor(const int row, const int column, const QColor color)
{
    START_PROFILE;

    if (mForegroundColors.at(row).at(column))
    {
        *mForegroundColors[row][column]=color;
    }
    else
    {
        mForegroundColors[row][column]=new QColor(color);
    }

    END_PROFILE("void FastTableWidget::setForegroundColor(const int row, const int column, const QColor color)");
}

QColor FastTableWidget::horizontalHeader_ForegroundColor(const int row, const int column)
{
    START_PROFILE;

    QColor *aColor=mHorizontalHeader_ForegroundColors.at(row).at(column);

    if (aColor==0)
    {
        aColor=&mHorizontalHeader_DefaultForegroundColor;
    }

    END_PROFILE("QColor FastTableWidget::horizontalHeader_ForegroundColor(const int row, const int column)");

    return *aColor;
}

void FastTableWidget::horizontalHeader_SetForegroundColor(const int row, const int column, const QColor color)
{
    START_PROFILE;

    if (mHorizontalHeader_ForegroundColors.at(row).at(column))
    {
        *mHorizontalHeader_ForegroundColors[row][column]=color;
    }
    else
    {
        mHorizontalHeader_ForegroundColors[row][column]=new QColor(color);
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_SetForegroundColor(const int row, const int column, const QColor color)");
}

QColor FastTableWidget::verticalHeader_ForegroundColor(const int row, const int column)
{
    START_PROFILE;

    QColor *aColor=mVerticalHeader_ForegroundColors.at(row).at(column);

    if (aColor==0)
    {
        aColor=&mVerticalHeader_DefaultForegroundColor;
    }

    END_PROFILE("QColor FastTableWidget::verticalHeader_ForegroundColor(const int row, const int column)");

    return *aColor;
}

void FastTableWidget::verticalHeader_SetForegroundColor(const int row, const int column, const QColor color)
{
    START_PROFILE;

    if (mVerticalHeader_ForegroundColors.at(row).at(column))
    {
        *mVerticalHeader_ForegroundColors[row][column]=color;
    }
    else
    {
        mVerticalHeader_ForegroundColors[row][column]=new QColor(color);
    }

    END_PROFILE("void FastTableWidget::verticalHeader_SetForegroundColor(const int row, const int column, const QColor color)");
}

QFont FastTableWidget::cellFont(const int row, const int column)
{
    if (mCellFonts.at(row).at(column))
    {
        return *mCellFonts.at(row).at(column);
    }

    return this->font();
}

void FastTableWidget::setCellFont(const int row, const int column, const QFont font)
{
    START_PROFILE;

    if (mCellFonts.at(row).at(column))
    {
        *mCellFonts[row][column]=font;
    }
    else
    {
        mCellFonts[row][column]=new QFont(font);
    }

    END_PROFILE("void FastTableWidget::setCellFont(const int row, const int column, const QFont font)");
}

QFont FastTableWidget::horizontalHeader_CellFont(const int row, const int column)
{
    if (mHorizontalHeader_CellFonts.at(row).at(column))
    {
        return *mHorizontalHeader_CellFonts.at(row).at(column);
    }

    return this->font();
}

void FastTableWidget::horizontalHeader_SetCellFont(const int row, const int column, const QFont font)
{
    START_PROFILE;

    if (mHorizontalHeader_CellFonts.at(row).at(column))
    {
        *mHorizontalHeader_CellFonts[row][column]=font;
    }
    else
    {
        mHorizontalHeader_CellFonts[row][column]=new QFont(font);
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_SetCellFont(const int row, const int column, const QFont font)");
}

QFont FastTableWidget::verticalHeader_CellFont(const int row, const int column)
{
    if (mVerticalHeader_CellFonts.at(row).at(column))
    {
        return *mVerticalHeader_CellFonts.at(row).at(column);
    }

    return this->font();
}

void FastTableWidget::verticalHeader_SetCellFont(const int row, const int column, const QFont font)
{
    START_PROFILE;

    if (mVerticalHeader_CellFonts.at(row).at(column))
    {
        *mVerticalHeader_CellFonts[row][column]=font;
    }
    else
    {
        mVerticalHeader_CellFonts[row][column]=new QFont(font);
    }

    END_PROFILE("void FastTableWidget::verticalHeader_SetCellFont(const int row, const int column, const QFont font)");
}

int FastTableWidget::cellTextFlags(const int row, const int column)
{
    return mCellTextFlags.at(row).at(column);
}

void FastTableWidget::setCellTextFlags(const int row, const int column, const int flags)
{
    START_PROFILE;

    mCellTextFlags[row][column]=flags;

    END_PROFILE("void FastTableWidget::setCellTextFlags(const int row, const int column, const int flags)");
}

int FastTableWidget::horizontalHeader_CellTextFlags(const int row, const int column)
{
    return mHorizontalHeader_CellTextFlags.at(row).at(column);
}

void FastTableWidget::horizontalHeader_SetCellTextFlags(const int row, const int column, const int flags)
{
    START_PROFILE;

    mHorizontalHeader_CellTextFlags[row][column]=flags;

    END_PROFILE("void FastTableWidget::horizontalHeader_SetCellTextFlags(const int row, const int column, const int flags)");
}

int FastTableWidget::verticalHeader_CellTextFlags(const int row, const int column)
{
    return mVerticalHeader_CellTextFlags.at(row).at(column);
}

void FastTableWidget::verticalHeader_SetCellTextFlags(const int row, const int column, const int flags)
{
    START_PROFILE;

    mVerticalHeader_CellTextFlags[row][column]=flags;

    END_PROFILE("void FastTableWidget::verticalHeader_SetCellTextFlags(const int row, const int column, const int flags)");
}

void FastTableWidget::clearSpans()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            mCellMergeX[i][j]=1;
            mCellMergeY[i][j]=1;
            mCellMergeParentRow[i][j]=-1;
            mCellMergeParentColumn[i][j]=-1;
        }
    }

    END_PROFILE("void FastTableWidget::clearSpans()");
}

void FastTableWidget::setSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)
{
    START_PROFILE;

    if (row+rowSpan>mRowCount)
    {
        rowSpan=mRowCount-row;
    }

    if (column+columnSpan>mColumnCount)
    {
        columnSpan=mColumnCount-column;
    }

    if (rowSpan<1)
    {
        rowSpan=1;
    }

    if (columnSpan<1)
    {
        columnSpan=1;
    }

    int parentRow;
    int parentColumn;

    for (int i=0; i<rowSpan; i++)
    {
        for (int j=0; j<columnSpan; j++)
        {
            parentRow=mCellMergeParentRow.at(row+i).at(column+j);
            parentColumn=mCellMergeParentColumn.at(row+i).at(column+j);

            if (parentRow>=0 && parentColumn>=0)
            {
                int parentSpanX=mCellMergeX.at(parentRow).at(parentColumn);
                int parentSpanY=mCellMergeY.at(parentRow).at(parentColumn);

                for (int g=0; g<parentSpanY; g++)
                {
                    for (int h=0; h<parentSpanX; h++)
                    {
                        mCellMergeParentRow[parentRow+g][parentColumn+h]=-1;
                        mCellMergeParentColumn[parentRow+g][parentColumn+h]=-1;
                    }
                }

                mCellMergeX[parentRow][parentColumn]=1;
                mCellMergeY[parentRow][parentColumn]=1;
            }

            mCellMergeParentRow[row+i][column+j]=row;
            mCellMergeParentColumn[row+i][column+j]=column;
        }
    }

    mCellMergeX[row][column]=columnSpan;
    mCellMergeY[row][column]=rowSpan;

    if (rowSpan==1 && columnSpan==1)
    {
        mCellMergeParentRow[row][column]=-1;
        mCellMergeParentColumn[row][column]=-1;
    }

    END_PROFILE("void FastTableWidget::setSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)");
}

quint16 FastTableWidget::rowSpan(const int row, const int column)
{
    START_PROFILE;

    return mCellMergeY.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::rowSpan(const int row, const int column)");
}

quint16 FastTableWidget::columnSpan(const int row, const int column)
{
    START_PROFILE;

    return mCellMergeX.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::columnSpan(const int row, const int column)");
}

QPoint FastTableWidget::spanParent(const int row, const int column)
{
    START_PROFILE;

    return QPoint(mCellMergeParentColumn.at(row).at(column), mCellMergeParentRow.at(row).at(column));

    END_PROFILE("QPoint FastTableWidget::spanParent(const int row, const int column)");
}

void FastTableWidget::horizontalHeader_ClearSpans()
{
    START_PROFILE;

    for (int i=0; i<mHorizontalHeader_RowCount; ++i)
    {
        for (int j=0; j<mColumnCount; ++j)
        {
            mHorizontalHeader_CellMergeX[i][j]=1;
            mHorizontalHeader_CellMergeY[i][j]=1;
            mHorizontalHeader_CellMergeParentRow[i][j]=-1;
            mHorizontalHeader_CellMergeParentColumn[i][j]=-1;
        }
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_ClearSpans()");
}

void FastTableWidget::horizontalHeader_SetSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)
{
    START_PROFILE;

    if (row+rowSpan>mHorizontalHeader_RowCount)
    {
        rowSpan=mHorizontalHeader_RowCount-row;
    }

    if (column+columnSpan>mColumnCount)
    {
        columnSpan=mColumnCount-column;
    }

    if (rowSpan<1)
    {
        rowSpan=1;
    }

    if (columnSpan<1)
    {
        columnSpan=1;
    }

    int parentRow;
    int parentColumn;

    for (int i=0; i<rowSpan; i++)
    {
        for (int j=0; j<columnSpan; j++)
        {
            parentRow=mHorizontalHeader_CellMergeParentRow.at(row+i).at(column+j);
            parentColumn=mHorizontalHeader_CellMergeParentColumn.at(row+i).at(column+j);

            if (parentRow>=0 && parentColumn>=0)
            {
                int parentSpanX=mHorizontalHeader_CellMergeX.at(parentRow).at(parentColumn);
                int parentSpanY=mHorizontalHeader_CellMergeY.at(parentRow).at(parentColumn);

                for (int g=0; g<parentSpanY; g++)
                {
                    for (int h=0; h<parentSpanX; h++)
                    {
                        mHorizontalHeader_CellMergeParentRow[parentRow+g][parentColumn+h]=-1;
                        mHorizontalHeader_CellMergeParentColumn[parentRow+g][parentColumn+h]=-1;
                    }
                }

                mHorizontalHeader_CellMergeX[parentRow][parentColumn]=1;
                mHorizontalHeader_CellMergeY[parentRow][parentColumn]=1;
            }

            mHorizontalHeader_CellMergeParentRow[row+i][column+j]=row;
            mHorizontalHeader_CellMergeParentColumn[row+i][column+j]=column;
        }
    }

    mHorizontalHeader_CellMergeX[row][column]=columnSpan;
    mHorizontalHeader_CellMergeY[row][column]=rowSpan;

    if (rowSpan==1 && columnSpan==1)
    {
        mHorizontalHeader_CellMergeParentRow[row][column]=-1;
        mHorizontalHeader_CellMergeParentColumn[row][column]=-1;
    }

    END_PROFILE("void FastTableWidget::horizontalHeader_SetSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)");
}

quint16 FastTableWidget::horizontalHeader_RowSpan(const int row, const int column)
{
    START_PROFILE;

    return mHorizontalHeader_CellMergeY.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::horizontalHeader_RowSpan(const int row, const int column)");
}

quint16 FastTableWidget::horizontalHeader_ColumnSpan(const int row, const int column)
{
    START_PROFILE;

    return mHorizontalHeader_CellMergeX.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::horizontalHeader_ColumnSpan(const int row, const int column)");
}

QPoint FastTableWidget::horizontalHeader_SpanParent(const int row, const int column)
{
    START_PROFILE;

    return QPoint(mHorizontalHeader_CellMergeParentColumn.at(row).at(column), mHorizontalHeader_CellMergeParentRow.at(row).at(column));

    END_PROFILE("QPoint FastTableWidget::horizontalHeader_SpanParent(const int row, const int column)");
}

void FastTableWidget::verticalHeader_ClearSpans()
{
    START_PROFILE;

    for (int i=0; i<mRowCount; ++i)
    {
        for (int j=0; j<mVerticalHeader_ColumnCount; ++j)
        {
            mVerticalHeader_CellMergeX[i][j]=1;
            mVerticalHeader_CellMergeY[i][j]=1;
            mVerticalHeader_CellMergeParentRow[i][j]=-1;
            mVerticalHeader_CellMergeParentColumn[i][j]=-1;
        }
    }

    END_PROFILE("void FastTableWidget::verticalHeader_ClearSpans()");
}

void FastTableWidget::verticalHeader_SetSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)
{
    START_PROFILE;

    if (row+rowSpan>mRowCount)
    {
        rowSpan=mRowCount-row;
    }

    if (column+columnSpan>mVerticalHeader_ColumnCount)
    {
        columnSpan=mVerticalHeader_ColumnCount-column;
    }

    if (rowSpan<1)
    {
        rowSpan=1;
    }

    if (columnSpan<1)
    {
        columnSpan=1;
    }

    int parentRow;
    int parentColumn;

    for (int i=0; i<rowSpan; i++)
    {
        for (int j=0; j<columnSpan; j++)
        {
            parentRow=mVerticalHeader_CellMergeParentRow.at(row+i).at(column+j);
            parentColumn=mVerticalHeader_CellMergeParentColumn.at(row+i).at(column+j);

            if (parentRow>=0 && parentColumn>=0)
            {
                int parentSpanX=mVerticalHeader_CellMergeX.at(parentRow).at(parentColumn);
                int parentSpanY=mVerticalHeader_CellMergeY.at(parentRow).at(parentColumn);

                for (int g=0; g<parentSpanY; g++)
                {
                    for (int h=0; h<parentSpanX; h++)
                    {
                        mVerticalHeader_CellMergeParentRow[parentRow+g][parentColumn+h]=-1;
                        mVerticalHeader_CellMergeParentColumn[parentRow+g][parentColumn+h]=-1;
                    }
                }

                mVerticalHeader_CellMergeX[parentRow][parentColumn]=1;
                mVerticalHeader_CellMergeY[parentRow][parentColumn]=1;
            }

            mVerticalHeader_CellMergeParentRow[row+i][column+j]=row;
            mVerticalHeader_CellMergeParentColumn[row+i][column+j]=column;
        }
    }

    mVerticalHeader_CellMergeX[row][column]=columnSpan;
    mVerticalHeader_CellMergeY[row][column]=rowSpan;

    if (rowSpan==1 && columnSpan==1)
    {
        mVerticalHeader_CellMergeParentRow[row][column]=-1;
        mVerticalHeader_CellMergeParentColumn[row][column]=-1;
    }

    END_PROFILE("void FastTableWidget::verticalHeader_SetSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan)");
}

quint16 FastTableWidget::verticalHeader_RowSpan(const int row, const int column)
{
    START_PROFILE;

    return mVerticalHeader_CellMergeY.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::verticalHeader_RowSpan(const int row, const int column)");
}

quint16 FastTableWidget::verticalHeader_ColumnSpan(const int row, const int column)
{
    START_PROFILE;

    return mVerticalHeader_CellMergeX.at(row).at(column);

    END_PROFILE("quint16 FastTableWidget::verticalHeader_ColumnSpan(const int row, const int column)");
}

QPoint FastTableWidget::verticalHeader_SpanParent(const int row, const int column)
{
    START_PROFILE;

    return QPoint(mVerticalHeader_CellMergeParentColumn.at(row).at(column), mVerticalHeader_CellMergeParentRow.at(row).at(column));

    END_PROFILE("QPoint FastTableWidget::verticalHeader_SpanParent(const int row, const int column)");
}
