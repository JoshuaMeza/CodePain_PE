from matplotlib import pyplot

def genGraphic1(casesAmount,deathsAmount):
    """
    Function that generates the first graphic
    Args:
        casesAmount (int): Total amount of confirmed cases
        deathsAmount (int): Total amount of deathsths
        parts (list): List of the two titles of the graphic
        slices (list): Parts of the graphic
        colors (list): Colors that the graphic will use
        values (list): Values with which size is defined
    Returns:
        Nothing
    """
    if casesAmount[0]!=0 and deathsAmount[0]!=0:
        parts = ('Confirmed Cases', 'Deaths')
        slices = (casesAmount[0], deathsAmount[0])
        colors = ('green', 'red')
        values = (0.1, 0)
        pyplot.rcParams['toolbar'] = 'None'
        
        _, _, text = pyplot.pie(slices, colors = colors, labels = parts, autopct='%1.1f%%', explode=values, startangle = 90)
        
        for tex in text:
            tex.set_color('white')
        
        pyplot.axis('equal')
        pyplot.title('Graph of the data collected from the country')
        pyplot.show()
